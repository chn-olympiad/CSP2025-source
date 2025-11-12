#include <bits/stdc++.h>
using namespace std;

const int MAXN=5e5+1;
int n, k, k1, ans;
int a[MAXN];
bool state=true;

void find(int l, int r, int m)
{
	if (l>r || m>n || l==r&&m>1)
		return;
	if (m==0)
		m=1;
	
	for (int i=m; i<=r-l; i++)
	{
		for (int j=l; j<=r-l-i; j++)
		{
			k1 = 0;
			for (int j1=j; j1<j+i; j1++)
				k1 = k1|a[j1];
			if (k1 == k)
			{
				ans++;
				find(l, j, m-1);
				find(j+i, r, m-1);
				return;
			}
		}
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	if (k==0 || k==1 || k==(1<<1) || k==(1<<2) || k==(1<<3) || k==(1<<4) || k==(1<<5) || k==(1<<6) || k==(1<<7) || k==(1<<8) || k==(1<<9) || k==(1<<10) || 
		k==(1<<11) || k==(1<<12) || k==(1<<13) || k==(1<<14) || k==(1<<15) || k==(1<<16) || k==(1<<17) || k==(1<<18) || k==(1<<19) || k==(1<<20))
	{
		for (int i=0; i<n; i++)
			if (a[i]==k)
				ans++;
	}
	else
	{
		find(0, n, 1);
	}
	
	printf("%d", ans);
	return 0;
}