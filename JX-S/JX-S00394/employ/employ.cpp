#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
// remember to use return with han'shu
const int N=2e5+10,mod=998244353;
int n,m,c[N];
ll ans;
bool vis[N];
char s[N];
string p;
void dfs(int day,int x,int cnt,int leave){
	if(leave>n-m) return ;
	if(cnt>=m){
		ll res=1;
		For(i,1,n-day+1) res=res*i%mod;
		ans=ans+res%mod;
		return ;
	}
	if(c[x]<=leave){
		leave++;
		For(i,1,n){
			if(vis[i]) continue;
			vis[i]=1;
			dfs(day+1,i,cnt,leave);
			vis[i]=0;
		}
		if(day==n && cnt>=m) ans++;
		return ;
	}
	if(s[day]=='0') leave++;
	else cnt++;
	if(leave>n-m) return ;
	if(cnt>=m){
		ll res=1;
		For(i,1,n-day) res=res*i%mod;
		ans=ans+res%mod;
		return ;
	}
	For(i,1,n){
		if(vis[i]) continue;
		vis[i]=1;
		dfs(day+1,i,cnt,leave);
		vis[i]=0;
	}
	if(day==n){
		if(cnt>=m) ans++;
		return ;
	}
	return ;
}
signed main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s+1;
	For(i,1,n) cin>>c[i];
	For(i,1,n)
		vis[i]=1,dfs(1,i,0,0),vis[i]=0;
	cout<<ans%mod<<endl;
	return 0;
}
