#include<bits/stdc++.h>
using namespace std;
int n,a[5001],ans=0;
int c(int x,int y){
	int v=1;
	for(int i=x;i>=x-y;i--) v*=i;
	for(int i=y;i>=1;i--) v/=i;
	return v;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	for(int i=3;i<n;i++) ans+=c(n,i);
	ans++;
	cout<<ans;
	return 0;
}
