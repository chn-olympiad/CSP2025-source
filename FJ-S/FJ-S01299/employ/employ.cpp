#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=505;
int c[N];
bool vis[N];
int anss[N];
int n,m;
string s;
int ans;
void dfs(int x,int step){
	if(vis[x])return;
	anss[step]=x;
	if(step==n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||c[anss[i]]<=cnt){
				cnt++;
			}
		}
		if(n-cnt>=m){
			ans++;
		}
		return ;
	}
	vis[x]=1;
	anss[step]=x;
	for(int i=1;i<=n;i++){
		dfs(i,step+1);
	}
	vis[x]=0;
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt++;
	}
	bool flag=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'){
			flag=1;
		}
	}
	if(m==n){
		if(cnt>0||!flag){
			cout<<0<<'\n';
			return 0;
		}
		else {
			long long res=1;
			for(int i=1;i<=n;i++){
				res*=i;
				res%=mod;
			}
			cout<<res<<"\n";
			return 0;
		}
	}
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
 } 
