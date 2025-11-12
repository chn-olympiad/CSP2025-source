# include <bits/stdc++.h>
# define int long long
using namespace std;

const int N = 5e5+5;
int n,k,a[N],f[N],maxx,b[N];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	for (int i = 1; i <= n; i++)
	{
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		for (int j = i; j <= n; j++) b[j] = a[j];
		for (int j = i+1; j <= n; j++)
		{
			if (b[j-1] == k) f[j] = f[j-1] + 1;
			else f[j] = f[j-1],b[j] = (b[j] ^ b[j-1]);
		}	
		maxx = max(maxx,b[n] == k ? f[n] + 1 : f[n]);
	}
	printf("%lld",maxx);
	fclose(stdin);
	fclose(stdout);
}
