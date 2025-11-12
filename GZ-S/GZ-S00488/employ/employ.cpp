//GZ-S00488 遵义市第四中学 雍大有 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10005,mod=998244353;
ll n,ans,m,c[N],p[105];
bitset<105> vis;
bool typ1=1;
string s;
void dfs(ll pla,ll cnt){
	if(n-pla+cnt+1<m)return;
	if(pla==n+1){
		if(cnt>=m)++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1;
		if(s[pla]!='0'&&c[i]>pla-cnt-1)dfs(pla+1,cnt+1);
		else dfs(pla+1,cnt);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s="|"+s;
	ll cnt=0;
	for(int i=1;i<=n;++i){
		cin>>c[i];
		if(typ1&&s[i]=='0')typ1=0;
		if(c[i])++cnt;
	}
	if(cnt<m){
		cout<<0;
	}else if(n<=100){
		dfs(1,0);
		cout<<ans;
	}
	return 0;
}
