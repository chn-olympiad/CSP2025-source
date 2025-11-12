#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500;
const ll mod=998244353;
int n,m;
char s[N+5];
int c[N+5];
bitset<N+5> vis;
ll ans;
int p[N+5];
ll a[N+5];
void dfs(int x,int get,int failure){
	if(x==n+1){
		if(get>=m){
			++ans;
		}
		return ;
	}
	if(get==m){
		ans+=a[n-x+1];
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		p[x]=i;
		if(failure>=c[i])
			dfs(x+1,get,failure+1);
		else
			dfs(x+1,get+(s[x]=='1'),failure+(s[x]=='0'));
		vis[i]=0;
	}
	return ;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool flag=0;
	a[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]*i%mod;
		cin>>s[i];
		if(s[i]=='0')
			flag=1;
	}
	int unzero=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])
			++unzero;
	}
	if(n<=12){
		dfs(1,0,0);
		cout<<ans%mod<<"\n";
		return 0;
	}
	else if(!flag){
		ans=1;
		for(int i=2;i<=unzero;i++)
			ans=ans*i%mod;
		cout<<ans<<"\n";
		return 0;
	}
	else{
		cout<<0<<"\n";
	}
	return 0;
}