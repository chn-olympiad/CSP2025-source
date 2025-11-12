#include <bits/stdc++.h>
#define ll long long
#define max(a,b) a>b?a:b
using namespace std;
const int N=5e5+5;
ll a[N],Xor[N];
ll dp1[N],dp2[N],flag[N];
int n,k;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(register int i=1; i<=n; ++i) scanf("%lld",&a[i]),Xor[i]=Xor[i-1]^a[i];
	for(register int i=1; i<=n; ++i) {
		register const int nw=Xor[i]^k;
		dp1[i]=max(dp1[i],dp1[i-1]);
		if(flag[nw]) dp1[i]=max(dp1[i],dp2[nw]+1);
		flag[Xor[i]]=1;
		dp2[Xor[i]]=max(dp2[Xor[i]],dp1[i]);
	}
	printf("%lld",dp1[n]);
}
