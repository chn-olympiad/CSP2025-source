#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll c[510];
string s;
ll p[510];
ll give_up,not_give,no_use,ans;
ll mod=998244353;
ll sA[510];
void solve_A(){
	sA[0]=1;
	for(int i=1;i<=n-no_use;i++)
		sA[i]=((sA[i-1]%mod)*(i%mod))%mod;
	cout<<sA[n];
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		p[i]=i;
		if(c[i]==0) no_use++;
	}
	if(no_use>m){
		cout<<0;
		return 0;
	}
	if(n>11){
		solve_A();
		return 0;
	} 
	do{
		give_up=not_give=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||c[p[i]]<=give_up)
				give_up++;
			else
				not_give++;
		}
		if(not_give>=m) ans=(ans+1)%mod;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}

