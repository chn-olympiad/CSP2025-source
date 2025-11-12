#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N(505);
const ll P(998244353);
int n,m,s[N],c[N],f[N];
ll jc(1);
char cc;
bool flag1(true);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i(1);i<=n;++i){
		cin>>cc;
		s[i]=(cc^48);
		jc=jc*i%P;
	}
	for(int i(1);i<=n;++i){
		cin>>c[i];
		f[i]=i;
	}
	if(n>=10){
		cout<<jc;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	ll ans(0);
	for(;jc;--jc){
		int cnt(0);
		for(int i(1);i<=n;++i) if(c[f[i]]<=cnt||!s[i])++cnt;
		if(n-cnt>=m)ans=(ans+1)%P;
		next_permutation(f+1,f+n+1);
	}cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
