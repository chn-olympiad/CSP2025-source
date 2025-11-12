#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout<<#x<<'='<<x<<endl;
#define ll long long
const ll mod=998244353;
string s,ss;
int c[510];
int p[510];
int vis[510];
ll fun[510];
int ans=0;
int n,m;
void dfs(int step){
	if(step==n+1){
		int luqu=0,taotai=0;
		for(int i=1;i<=n;i++){
			if(taotai>=c[p[i]]){
				taotai++;
				continue;
			}
			if(s[i]=='1')luqu++;
			else taotai++;
		}
		if(luqu>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>ss;
	s=' '+ss;
	for(int i=1;i<=n;i++)cin>>c[i];
	int f=1;
	for(int i=1;i<=n;i++)if(s[i]=='0')f=0;
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=(c[i]>0);
	fun[0]=fun[1]=1;
	for(int i=2;i<=n;i++)fun[i]=fun[i-1]*(1ll*i)%mod;
	if(m==n){
		if(f&&cnt==n)cout<<fun[n];
		else cout<<0;
	}
	else if(f){
		if(cnt>=m){
			cout<<fun[n];
		}
		else{
			cout<<0;
		}
	}
	else {
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
} 
