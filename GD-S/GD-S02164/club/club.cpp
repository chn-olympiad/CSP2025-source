#include <bits/stdc++.h>
using namespace std;
struct r
{
	int w,v;
}a[10010],b[10010],c[10010];
bool x[10010];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t > 0)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int n,maxn = 0;
		cin >> n;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i].w >> b[i].w >> c[i].w;
			a[i].v = i,b[i].v = i,c[i].v = i;
		}
		for (int i = 1;i < n;i++)
		{
			for (int j = i+1;j <= n;j++)
			{
				if (a[i].w < a[j].w) swap(a[i],a[j]);
				if (b[i].w < b[j].w) swap(b[i],b[j]);
				if (c[i].w < c[j].w) swap(c[i],c[j]);
			}
		}
		int a1=1,a2=1,a3=1,mid = n/2,ans = 0;
		memset(x,0,sizeof(x));
		for (int i = 1;i <= n;i++)
		{
			if (a1<= mid && x[a[i].v] == 0 && a[1].w!= 0)
			{
				ans +=a[i].w;
				x[a[i].v] = 1;
				a1++;
			}
			if (a2<= mid && x[b[i].v] == 0 && b[1].w!= 0)
			{
				ans +=b[i].w;
				x[b[i].v] = 1;
				a2++;
			}
			if (a3<= mid && x[c[i].v] == 0 && c[1].w!= 0)
			{
				ans +=c[i].w;
				x[c[i].v] = 1;
				a3++;
			}
		}
		if (ans > maxn) maxn = ans;//123
		
		a1=1,a2=1,a3=1,mid = n/2,ans = 0;
		memset(x,0,sizeof(x));
		for (int i = 1;i <= n;i++)
		{
		
			if (a2<= mid && x[b[i].v] == 0 && b[1].w!= 0)
			{
				ans +=b[i].w;
				x[b[i].v] = 1;
				a2++;
			}
			if (a1<= mid && x[a[i].v] == 0 && a[1].w!= 0)
			{
				ans +=a[i].w;
				x[a[i].v] = 1;
				a1++;
			}
			if (a3<= mid && x[c[i].v] == 0 && c[1].w!= 0)
			{
				ans +=c[i].w;
				x[c[i].v] = 1;
				a3++;
			}
		}
		if (ans > maxn) maxn = ans;//213
		a1=1,a2=1,a3=1,mid = n/2,ans = 0;
		memset(x,0,sizeof(x));
		for (int i = 1;i <= n;i++)
		{
			if (a3<= mid && x[c[i].v] == 0 && c[1].w!= 0)
			{
				ans +=c[i].w;
				x[c[i].v] = 1;
				a3++;
			}
			if (a1<= mid && x[a[i].v] == 0 && a[1].w!= 0)
			{
				ans +=a[i].w;
				x[a[i].v] = 1;
				a1++;
			}
			if (a2<= mid && x[b[i].v] == 0 && b[1].w!= 0)
			{
				ans +=b[i].w;
				x[b[i].v] = 1;
				a2++;
			}
		}
		if (ans > maxn) maxn = ans;//312
		
		a1=1,a2=1,a3=1,mid = n/2,ans = 0;
		memset(x,0,sizeof(x));
		for (int i = 1;i <= n;i++)
		{
			if (a3<= mid && x[c[i].v] == 0 && c[1].w!= 0)
			{
				ans +=c[i].w;
				x[c[i].v] = 1;
				a3++;
			}
			if (a2<= mid && x[b[i].v] == 0 && b[1].w!= 0)
			{
				ans +=b[i].w;
				x[b[i].v] = 1;
				a2++;
			}
			if (a1<= mid && x[a[i].v] == 0 && a[1].w!= 0)
			{
				ans +=a[i].w;
				x[a[i].v] = 1;
				a1++;
			}
		}
		if (ans > maxn) maxn = ans;//321
	
		a1=1,a2=1,a3=1,mid = n/2,ans = 0;
		memset(x,0,sizeof(x));
		for (int i = 1;i <= n;i++)
		{
			if (a1<= mid && x[a[i].v] == 0 && a[1].w!= 0)
			{
				ans +=a[i].w;
				x[a[i].v] = 1;
				a1++;
			}
			if (a3<= mid && x[c[i].v] == 0 && c[1].w!= 0)
			{
				ans +=c[i].w;
				x[c[i].v] = 1;
				a3++;
			}
			if (a2<= mid && x[b[i].v] == 0 && b[1].w!= 0)
			{
				ans +=b[i].w;
				x[b[i].v] = 1;
				a2++;
			}
		}
		if (ans > maxn) maxn = ans;//132
		
		a1=1,a2=1,a3=1,mid = n/2,ans = 0;
		memset(x,0,sizeof(x));
		for (int i = 1;i <= n;i++)
		{
			if (a2<= mid && x[b[i].v] == 0 && b[1].w!= 0)
			{
				ans +=b[i].w;
				x[b[i].v] = 1;
				a2++;
			}
			if (a3<= mid && x[c[i].v] == 0 && c[1].w != 0)
			{
				ans +=c[i].w;
				x[c[i].v] = 1;
				a3++;
			}
			if (a1<= mid && x[a[i].v] == 0 && a[1].w!=0)
			{
				ans +=a[i].w;
				x[a[i].v] = 1;
				a1++;
			}
		}
		if (ans > maxn) maxn = ans;//231
		
		
		cout << maxn << endl;
		t--;
	}
	return 0;
}
// 1 4 17283 8662 0 14077 12328 0 3565 1739 0 4582 15426 0
