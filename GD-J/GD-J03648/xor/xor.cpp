#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5, M=3e6+5;

int n, k, a[N], s[N], f[N], mx[M], vis[M];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]), s[i]=(s[i-1]^a[i]);
	
	vis[0]=1;
	for (int i=1; i<=n; i++)
	{
		f[i]=f[i-1];
		if (vis[s[i]^k]) f[i]=max(f[i], mx[s[i]^k]+1);
		mx[s[i]]=max(mx[s[i]], f[i]), vis[s[i]]=1;
	}

//	for (int i=1; i<=n; i++)
//	{
//		f[i]=f[i-1];
//		for (int j=0; j<i; j++)
//		{
//			if ((s[i]^s[j])==k) f[i]=max(f[i], f[j]+1);
//		}
//	}
	
	printf("%d", f[n]);
	return 0;
} 
/*
4 2
2 1 0 3

4 3
2 1 0 3

4 0
2 1 0 3

6 3
1 1 4 5 1 4

9 3
1 3 2 4 2 3 1 2 3

6 3
3 4 3 1 2 3
*/
