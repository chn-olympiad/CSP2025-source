#include<bits/stdc++.h>
#define eps 1e-6
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> pii;
#define fi first
#define se second
#define MOD 998244353
#define MAXN 300005
signed main(){
	LD s=0;
	int k=10,n=10000;
	for(int j=0;j<(1<<k);j++){
		int t=1;
		for(int i=0;i<k;i++)
			if((j>>i)&1)t++;
		s+=t*log(t)/log(2);
	}
	cout<<(LL)(s*n+20000000+k*n*log(n)/log(2));

	return 0;
}