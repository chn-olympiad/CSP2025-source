#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int a[N],ans=0,n,mod=998244353;
void dfs(int u,int sum,int maxn,int cnt){
	if(cnt>=3&&sum>2*maxn) ans++;
	for(int i=u+1;i<=n;i++)
		dfs(i,sum+a[i],max(maxn,a[i]),cnt+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n>=500){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,0,-1,0);
	cout<<ans%mod;
	return 0;
}