#include<bits/stdc++.h>
using namespace std;
int n,m,a[400];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++)cin>>a[i];
	int s=a[1];
	sort(a+1,a+k+1,cmp);
	for(int r=1,c=1,i=1;i<=k;i++){
		if(a[i]==s){
			cout<<c<<" "<<r;
			break;
		}
		if(c%2<1){
			if(r==1)c++;
			else r--;
		}
		else{
			if(r==n)c++;
			else r++;
		}
	}
	return 0;
}
