#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;


struct node{
	int l, r;
	int k;
}tr[N*4];
int n, k;
int a[N];
int kl[N][N];
int dp[N][N];

void build(int p, int l, int r)
{
	tr[p].l = l;
	tr[p].r = r;
	if(l==r){
		tr[p].k = a[l];
		return;
	}
	int mid = (l+r)/2;
	build(p*2, l, mid);
	build(p*2+1, mid+1, r);
	tr[p].k = tr[p*2].k^tr[p*2+1].k;
}

int get(int l, int r, int p)
{
	//cout << l << ' ' << r << ' ' << p << ' ' << tr[p].k << ' ' << tr[p].l << ' ' << tr[p].r << ' ' << kl[l][r] << endl;
	if(kl[l][r]>=0) return kl[l][r];
	if(l==r) return kl[l][r]=a[l];
	if(l==tr[p].l&&r==tr[p].r)
	{
		return kl[l][r] = tr[p].k;
	}
	int mid = (tr[p].l+tr[p].r)/2;
	if(r<=mid)
	{
		return get(l, r, p*2);
	}
	if(l>=mid+1)
	{
		return get(l, r, p*2+1);
	}
	if(l<=mid&&r>=mid)
	{
		return kl[l][r] = get(l, mid, p*2)^get(mid+1, r, p*2+1);
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(kl, 128, sizeof(kl));
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) scanf("%d", a+i);
	build(1, 1, n);
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			if(get(j, j+i, 1)==k) dp[j][j+i] = 1;
			else dp[j][j+i] = 0;
			
			if(i!=0) 
			{
				for(int k=j;k<=j+i;k++)
				{
					dp[j][j+i] = max(dp[j][j+i], dp[j][k]+dp[k+1][j+i]);
				}
			}
		}
	}
	printf("%d", dp[1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
