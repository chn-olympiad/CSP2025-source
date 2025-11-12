#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;

const int N=510;
const int mod=998244353;
int n,m;
ll ans=0;
char s[N];
int c[N];
bool vis[N];

void dfs(int now,vector<int> p,int fail_cnt,int success_cnt){
	if(now==n+1){
		if(success_cnt>=m){
			++ans;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		vis[i]=1;
		p.push_back(i);
		int new_fail_cnt=fail_cnt;
		int new_success_cnt=success_cnt;
		if(fail_cnt>=c[i]){
			new_fail_cnt++;
		}else if(s[now]=='0'){
			new_fail_cnt++;
		}else if(s[now]=='1'){
			new_success_cnt++;
		}
		dfs(now+1,p,new_fail_cnt,new_success_cnt);
		p.pop_back();
		vis[i]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>(s+1);
	rep(i,1,n){
		cin>>c[i];
	}
	if(n<=18){
		vector<int> v;
		dfs(1,v,0,0);
		cout<<ans<<'\n';
		return 0;
	}
	return 0;
}

