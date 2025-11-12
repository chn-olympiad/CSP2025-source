#include<bits/stdc++.h>
using namespace std;
const int maxn=5010;
const int mod=998244353;
int n,a[maxn];
int ans=0;
void dfs(int x,int totl,int maxl,int k){
	maxl=max(a[k],maxl);
	if(x>=3&&totl>maxl*2){ans++; ans=ans%mod;}
	if(k==n) return;
	for(int i=k+1;i<=n;i++) dfs(x+1,totl+a[i],maxl,i);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) dfs(1,a[i],a[i],i);
	cout<<ans;
	return 0;
}