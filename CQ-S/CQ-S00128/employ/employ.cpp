#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=550,p=998244353;
int c[N],b[N],vis[N],n,m,ans;
char s[N];
void dfs(int dep){
	if(dep==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[b[i]]){
				cnt++;
				continue;
			}
			if(s[i]=='1') sum++;
			else cnt++;
		}
		if(sum>=m){
			ans=(ans+1)%p;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}

