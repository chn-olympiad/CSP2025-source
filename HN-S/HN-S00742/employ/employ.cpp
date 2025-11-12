#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod = 998244353;
const int N = 507;
string s;
int n,m,ans;
int cnt,sum,tp;
int c[N],jc[N];
int qpow(int x,int k){
	int res=1;
	while(k!=0){
		if(k&1) x*=x,x%=Mod;
		res*=res; res%=Mod; k>>=1;
	}return res;
}
int A(int p,int q){
	if(q>p) return 0;
	return jc[p]*qpow(jc[p-q],Mod-2)%Mod;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s; jc[1]=1;
	int len=s.size();
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) if(c[i]) cnt++;
	for(int i=2;i<=n;i++) jc[i]=(jc[i-1]*i)%Mod;
	for(int i=m;i<=min(cnt,len);i++) ans+=A(cnt,i),ans%=Mod;
	cout<<ans;
	return 0;
}
/*
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);

*/
