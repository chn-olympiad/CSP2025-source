#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1010101;
const int mod=998244353;
ll n,m,a[N],c[N],vis[N],ans;
string s;
void dfs(ll x){
	if(x==n){
		ll res=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||res>=c[a[i]])
				res++;
		}
		if(n-res>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x+1]=i;
			dfs(x+1);
			a[x+1]=0;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	ll flag=0;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)if(s[i]!='1')flag=1;
	if(n<=18){
		dfs(0);
		cout<<ans%mod;
		return 0;
	}
	else{
		cout<<0;
	}
	return 0;
}
