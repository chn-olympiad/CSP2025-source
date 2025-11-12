#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s,c=1,r=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(c%2==1){
			r++;
			if(r==n+1){
				r=n;
				c++;
			}
		}
		else{
			r--;
			if(r==0){
				r=1;
				c++;
			}
		}
		if(a[i]==s){
			cout<<c<<" "<<r;
			break;
		}
	}
	return 0;
}
