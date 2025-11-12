#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;
const int N=2e5+7;
const int M=1e6+7;
int T,n,m,k,q;
ll mod=998244353;
int a[N],b[N];
ll ksm(ll a,ll b){
	a%=mod;
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
bool TA(){
	bool f=1;
	rep(i,1,n) if(a[i]==0) return 0;
	int cnt=0;
	rep(i,1,n) if(b[i]) cnt++;
	if(cnt<m) cout<<0<<'\n';
	else{
		ll res=1;
		rep(i,1,cnt) res=res*i%mod;
		cout<<res<<'\n';
	}
	return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	string s;
	cin>>s;
	rep(i,1,n) a[i]=s[i-1]-'0';
	rep(i,1,n) cin>>b[i];
	if(TA()) return 0;
	cout<<0<<'\n';
	return 0;
}