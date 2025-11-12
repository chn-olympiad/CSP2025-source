#include<bits/stdc++.h>
#define ll long long
const int N=998244353;
using namespace std;
ll n,a[5010],dp[5010][5010],q[5010],ans,vis[5010],be,bi[5010];
void dfs(int x,int pos,ll he){
	if(pos==x+1){
		if(he>q[x]*2){
			ans++;
			ans%=N;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0&&a[i]>=q[pos-1]&&i>bi[pos-1]){
			vis[i]=1;
			q[pos]=a[i];
			bi[pos]=i;
			dfs(x,pos+1,he+a[i]);
			bi[pos]=0;
			q[pos]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		dfs(i,1,0);
	}
	cout<<ans;
	return 0;
}
// 60 minutes,but most to 50pts......
