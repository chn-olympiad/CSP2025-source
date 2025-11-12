#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=505;
int n,m,ans;
string s;
int a[MAXN];
bool vis[MAXN];
map<string,bool> mp;
void slove();
void dfs(int x,int k,int sum,int una);
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
//	cin>>T;
	while(T--){
		slove();
	}
	return 0;
}
void slove(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int tt;
		if(s[0]=='1') tt=1;
		else tt=0;
		dfs(i,1,tt,!tt);
	}
	cout<<ans;
	return ;
}
void dfs(int x,int k,int sum,int una){
	if(k>n) return;
	if(sum>=m){
		ans++;
	}
	
	vis[x]=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			int ww;
			if(s.size()-1>k) ww=k;
			else ww=s.size()-1;
			if(s[ww]=='0'||a[i]<=una){
				dfs(i,k+1,sum,una+1);
			}else{
				dfs(i,k+1,sum+1,una);
			}
		}
	}
	vis[x]=0;
	return ;
}
