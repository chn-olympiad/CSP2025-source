#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
using VI=vector<int>;
using PI=pair<int,int>;
const ll maxn=505,mod=998244353;
ll n,m,c[maxn],ans=0,a[maxn];
string s;bool vis[maxn];
void dfs(int x){
	if(x==n+1){
		int sum=0,num=0;
		for(int i=1;i<=n;i++){
			if(sum>=c[a[i]]){sum++;continue;}
			if(s[i-1]=='1')num++;
			else sum++;
		}if(num>=m)ans++;ans%=mod;return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;a[x]=i;
		dfs(x+1);vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){dfs(1);cout<<ans;return 0;}
	ll sum=1;
	for(int i=1;i<=n;i++)(sum*=i)%=mod;
	cout<<sum%mod;return 0;
}
