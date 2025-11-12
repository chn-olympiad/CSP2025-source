#include<bits/stdc++.h>
#define ll long long
#define bint __int128
#define pb push_back
#define mkp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define debug(x) cout<<#x<<" = "<<x<<endl
using namespace std;
const ll mod=998244353;
inline ll fpow(ll a,ll b){
	ll res=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)res=res*a%mod;
	return res;
}
const int N=505,S=1<<18;
int n,m,T;
string str;
int c[N];
ll f[S][19][19];
int Sub1(){
	int s=(1<<n)-1;
	f[0][0][0]=1;
	for(int i=0;i<s;i++){
		for(int l=0;l< n;l++)for(int t=0;t< n;t++)if(f[i][l][t]){
			for(int j=1;j<=n;j++)if((i>>(j-1)&1)==0){
				int k=i+(1<<(j-1)),p=__builtin_popcount(i)+1;
				if((l<c[j])&&(str[p]=='1'))(f[k][l][t+1]+=f[i][l][t])%=mod;
				else (f[k][l+1][t]+=f[i][l][t])%=mod;
			}
		}
	}
	ll res=0;
	for(int i=m;i<=n;i++)
		for(int j=0;j<=n;j++)
			(res+=f[s][j][i])%=mod;
	cout<<res<<endl;
	return 0;
}
int Sub3(){
	bool ck=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0)ck=1;
		if(str[i]=='0')ck=1;
	}
	if(ck)cout<<0<<endl;
	else{
		ll res=1;
		for(int i=1;i<=n;i++)res=res*i%mod;
		cout<<res<<endl;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str; str=' '+str;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=18)return Sub1();
	return Sub3();
}
