#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 998'244'353;
int a[5005];
long long f[5005][5005]; 

long long pow(long long a, long long b) {
	long long re = 1;
	while (b) {
		if (b & 1) re = re*a%mod;
		a = a*a%mod; b >>= 1; 
	}
	return re;
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	int n; scanf("%d",&n);
	for (int i = 1; i <= n; i++) 
		scanf("%d",a+i);
	sort(a+1,a+n+1); int mx = a[n];
	for (int j = 0; j <= mx; j++) f[0][j] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i]; j++)
			f[i][j] = f[i-1][j];
		for (int j = a[i]; j <= mx; j++) 
			f[i][j] += (f[i-1][j]+f[i-1][j-a[i]])%mod;
	}
	long long ans = 0;
	for (int i = 3; i <= n; i++)
		for (int j = 2; j < i; j++) 
			ans = ((ans+pow(2,j-1)-f[j-1][a[i]-a[j]])%mod+mod)%mod;
	printf("%lld",ans);
	return 0;
}

// 调了一万年的 DP 终于过了，现在已经看不懂转移方程了。 
// 密码：#soeng4sim3z-yok6shoey4 

/*
可爱的小兔子可以由西宁、海东南西北、黄南、果洛和唐古拉山组成。  
请还要是什么东西。 
*/ 
