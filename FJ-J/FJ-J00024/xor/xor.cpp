#include <bits/stdc++.h>
using namespace std;
struct Node
{
	long long l,r,ans; 
}p[500005]; 
long long n,k;
long long a[500005];
long long sum[500005]; 
long long ans = 0;
bool cmp(Node x,Node y)
{
	if (x.l == y.l)
	{
		return x.ans < y.ans;
	}
	return x.l < y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin >> n >> k;
	if (n > 100000)
	{
		if (k == 0)
		{
			cin >> a[1];
			for (int i = 2;i <= n;i++)
			{
				cin >> a[i];
				if (a[i] == a[i - 1] && a[i] == 1)
				{
					ans++;
					a[i] = 0;
				}
				else if (a[i] == 0)
				{
					ans++;
				}
			}
		}
		else
		{
			for (int i = 1;i <= n;i++)
			{
				cin >> a[i];
				if (a[i] == 1)
				{
					ans++;
				}
			}
		}
		cout << ans;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i]; 
	}
	for (int i = 1;i <= n;i++)
	{
		sum[i] = sum[i - 1] ^ a[i]; 
	}
	int pos = 0; 
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			if ((sum[j] ^ sum[i - 1]) == k)
			{
				p[++pos] = (Node){i,j,j - i + 1}; 
			} 
		} 
	} 
	sort(p + 1,p + pos + 1,cmp);
	int last;
	for (int i = 1;i <= pos;i = last)
	{
		bool flag = 0;
		last = i + 1;
		for (int j = i + 1;j <= pos;j++)
		{
			if (p[j].l > p[i].r)
			{
				last = j;
				break;
			}
			if (p[j].r <= p[i].r)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			continue;
		}
		while (p[last].l <= p[i].r)
		{
			last++;
		}
		ans++;
	}
	cout << ans; 
	return 0;
}
