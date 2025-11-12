#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int a[N];
int n,k;
int summ[N];
struct node
{
	int l, r;
}b[N];
int tot;
bool cmp(node x,node y)
{
	//if (x.r == y.r) return x.l < y.l;
	return x.r < y.r;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();
	freopen("xor.in","r",stdin);
	freopen("xor.out","w", stdout);
	cin >> n >> k;
	int flag = 1,mx = 0,sum = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		summ[i] = summ[i - 1] ^ a[i];
		if (a[i] == 1) sum++;
		if (a[i] != 1) flag = 0;
		mx = max(mx,a[i]);
	}
	if (flag)
	{
		if (k == 0) cout << n / 2;
		else if (k == 1) cout << n;
		else cout << 0;
	}
	else if (mx <= 1)
	{
		if (k == 1) cout << sum;
		else if (k == 0)
		{
			int ans = 0;
			if (a[1] == 0) ans++;
			for (int i = 2; i <= n; i++)
			{
				if (a[i] == 0) ans++;
				if (a[i] == 1 && a[i - 1] == 1) ans++;
			}
			cout << ans << endl;
		} 
		else cout << 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i; j <= n; j++)
			{
				int u = summ[j] ^ summ[i - 1];
				//cout << u << endl;
				if (u == k)
				{
					//cout << i << " " << j << endl;
					b[++tot].l = i;
					b[tot].r = j;
					break;
				}
			}
		}
		
		//cout << tot << endl;
		sort (b + 1,b + tot + 1,cmp);
		int h = 1,last= 1;
		for (int i = 2; i <= tot; i++)
		{
			if (b[i].l > b[last].r) h++,last = i;
		}
		cout << h << endl;
	}
	return 0;
}
