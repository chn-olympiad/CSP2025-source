#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=200010;
const int mod=998244353;
int n,m,k;
int a[maxn];
string s;
int fac[maxn];
int qzh[maxn];
int cnt=0;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	qzh[0]=1;
	for(int i = 1;i <= 500;i++) fac[i]=fac[i-1]*i%mod;
	cin >> n >> m;
	cin >> s;
	cnt=n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]==0)cnt--;
	}
	n=cnt;
//	cout << cnt << endl;
	cout << fac[n]/fac[n-m-1]*fac[m] << endl;
	return 0;
}
