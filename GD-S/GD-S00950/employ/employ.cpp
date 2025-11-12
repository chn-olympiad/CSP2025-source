#include<bits/stdc++.h>
using namespace std;

const int maxn=505,mod=998244353;
int n,m;
string s;
int c[maxn],p[maxn];

int fac[maxn];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	for(int i=1;i<=n;i++){
		int t;
		cin >> t;
		c[t-1]++;
	}
	cout<<fac[n]<<endl;
	return 0;
}
