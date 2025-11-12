#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;
const int MOD=998244353;
ll n,m,c[N],ans=0;
bool vis[N];
vector<int> g;
char s[N];
void dfs(int dep){
	if(dep==n){
		int tot=0;
		for(int i=1;i<=n;i++){
			int val=c[g[i-1]];
			if(s[i]=='0')tot++;
			else{
				if(val<=tot)tot++;
			}
		}
//		cout<<endl;
		if(n-tot>=m)ans++;
//		cout<<n-tot<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			g.push_back(i);
			dfs(dep+1);
			g.pop_back();
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n){
		bool vis=0;
		for(int i=1;i<=n;i++)if(s[i]=='0')vis=1;
		for(int i=1;i<=n;i++)if(c[i]==0)vis=1;
		if(vis){
			cout<<0;
			return 0;
		}
		ll cnt=1;
		for(int i=1;i<=n;i++)cnt=(cnt*i)%MOD;
		cout<<cnt<<'\n';
		return 0;
	}
	dfs(0);
	cout<<ans<<'\n';
	return 0;
} 
/*
T1写了1.5h，T2性质A j打成i调了快1h，T4对着错误思路调了快1h ，T3没看，
最后一个赛季CSP打的好烂。 
*/
