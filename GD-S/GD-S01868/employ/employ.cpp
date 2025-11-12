#include <bits/stdc++.h>
using namespace std;
const int P=998244353,maxn=505;
int sum[maxn],a[maxn],p[11],n,m;
string s;
inline void slv() {
	int res=0;
	for(int i=1;i<=n;++i) p[i]=i;
	do {
		int cnt=0;
		for(int i=1;i<=n;++i) {
			if(a[p[i]]<=cnt) ++cnt;
			else if(s[i-1]=='0') ++cnt;
		}
		if(cnt<=n-m) ++res;
	} while(next_permutation(p+1,p+n+1));
	cout<<res<<'\n';
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;++i) cin>>a[i];
	slv();
	return 0;
}
