#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int,int>;
const int maxn=1e4+10,mod=998244353;
int n,m;
string s;
int c[maxn];
int vis[maxn];
int num[maxn];
ll ans;
void dfs(int u){
	if(u>n){
		int cntn=0;
		for(int i=1;i<=n;i++){
			if(cntn>=c[num[i]]||s[i-1]=='0')cntn++;
		}
		ans+=((n-cntn)>=m);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			num[u]=i;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++)cin>>c[i],cnt+=(c[i]==0);
	if(n<=10){
		dfs(1);
		cout<<ans;
	}
	else{
		if(m>n-cnt)cout<<0;
		else{
			ans=1;
			for(int i=1;i<=n;i++)ans=1ll*ans*n%mod;
			cout<<ans;
		}
	}
} 
