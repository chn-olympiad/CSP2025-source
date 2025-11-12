#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const ll N=505;
ll n,m,c[N],ans;
string s;
ll p[N];
bool vis[N];
ll fac[N];

void init(){
	n=N-5;
	fac[0]=1;
	for(ll i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}
}

void sol(){
	ll cntrej=0,res=0;
	for(ll i=1;i<=n;i++){
		if(cntrej<c[p[i]]){
			if(s[i]=='1'){
				res++;
			}else{
				cntrej++;
			}
		}else{
			cntrej++;
		}

	}
	if(res>=m){
		ans++;
	}
}

void dfs(ll step){
	if(step>n){
		sol();
		return ;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		p[step]=i;
		vis[i]=1;
		dfs(step+1);
		vis[i]=0;
	}
	return ;
}

int main(){
	ios::sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	init();

	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	bool flagA=1;
	for(ll i=1;i<=n;i++){
		if(s[i]!='1') flagA=0;
	}
	if(n<=10){
		dfs(1);
		cout<<ans%mod;
		return 0;
	}
	if(m==n){
		if(!flagA){
			cout<<0;
			return 0;
		}
		for(ll i=1;i<=n;i++){
			if(c[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<fac[n]%mod;
	}
	if(flagA){
		
		return 0;
	}


	return 0;
}



/*
5 5
11111
1 2 3 4 5
*/