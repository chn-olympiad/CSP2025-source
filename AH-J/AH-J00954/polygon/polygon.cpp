#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[6001],ans;
int s[6001];
int dfs(int l,int r,int x,int u){
	int p=1;
	if(u==0||x==0) return p;
	for(int i=l;i<=r;i++){
		if(a[i]<=x){
			p+=dfs(i+1,r,x-a[i],u-1)%mod;
		}
	}
	return p%mod;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=3;i<=n;i++){
		if(a[i]<s[i-1]){
			int h=s[i-1]-a[i]-1;
			ans+=dfs(1,i-1,h,i-3)%mod;
		}
	}
	cout<<ans%mod;
	return 0;
}
