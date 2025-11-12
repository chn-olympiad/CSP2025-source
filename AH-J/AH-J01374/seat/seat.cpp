#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	for(int i=2;i<=n*m;i++){
		if(r==1&&c%2==0){
			c++;
		}else if(r==m&&c%2==1){
			c++;
		}else{
			if(c%2==1) r++;
			else r--;
		}
		if(a[i]==x) break;
	}
	cout<<c<<" "<<r<<"\n";
	return 0;
}
