#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5;

struct Edge
{
	ll U,V,W;
}a[9000005];

ll n,m,k,xz[12][N],lyy,cnt = 1,cnt2;
ll fa[N];

bool cmp(Edge A,Edge B)
{
	return A.W < B.W;
}

void kruskal()
{
	for(ll i = 1;i < n;i++)
	{
		while(cnt <= cnt2)
		{
			Edge now = a[cnt++];
			if(fa[now.U] != fa[now.V])
			{
				fa[now.U] = fa[now.V];
				lyy += now.W;
				break;
			}
		}
	}
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(ll i = 1;i <= m;i++)
	{
		cin >> a[i].U >> a[i].V >> a[i].W;
		fa[i] = i;
	}
	cnt2 = m;
	
	for(ll i = 1;i <= k;i++)
	{
		cin >> xz[i][0];
		for(int j = 1;j <= n;j++)
			cin >> xz[i][j];
	}
	
	for(ll i = 1;i <= n;i++)
	{
		for(ll j = i + 1;j <= n;j++)
		{
			ll gg = 0x3f3f3f3f3f3f3f3f;
			for(ll l = 1;l <= k;l++) gg = min(gg,xz[l][i] + xz[l][j] + xz[l][0]);
			a[++cnt2] = (Edge){i,j,gg};
		}
	}
	sort(a + 1,a + cnt2 + 1,cmp);
	
	kruskal();
	
	cout << lyy; 
	return 0;
}
