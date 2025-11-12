#include <bits/stdc++.h>
using namespace std;
long long n,b,c[1005],a[1005],cnt;
char s[105];
const long long MOD = 998244353; 
long long A(int n,int m)
{
	long long sumA = 1;
	for (int i = n;i >= m;i--) sumA*=i;
	sumA = abs(sumA);
	return sumA;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld %lld",&n,&b);
	cnt = n;
	scanf("%c",s);
	for (int i = 1;i <= n;i++) {
		scanf("%lld",&c[i]);
		a[i] += c[i-1];
	}
	for (int i = 1;i <= n;i++){
		if (a[i] >= c[i]) cnt--;
	}
	long long sum = (A(cnt,cnt)) % MOD;
	printf("%lld",sum);
	return 0;
}