#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 55;
int n, k, a[N], d[N], cur, ans, lst;
struct node
{
	int l, r;
}q[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		d[i] = d[i - 1] xor a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = i - 1; j >= 0; j--)
		{
			if((d[i] xor d[j]) == k)
			{
				q[++cur].l = j + 1;
				q[cur].r = i;
				break;
			}
		}
	}
	for(int i = 1; i <= cur; i++)
	{
		if(q[i].l > q[lst].r)
		{
			ans++;
			lst = i;
		}
	}
	cout << ans << endl;
	return 0;
}
