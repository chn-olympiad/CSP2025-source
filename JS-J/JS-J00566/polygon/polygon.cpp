#include<bits/stdc++.h>
using namespace std;

int a[5050];
int n;
long long cnt;

void mj(int x, int g, int h)
{
	if(g == 1)
	{
		for(int i=x+1; i<=n; i++)
		{
			if(h + a[i] > a[i] * 2) cnt++;
		}
		cnt %= 998244353;
		return;
	}
	for(int i=x+1; i<=n-g+1; i++)
	{
		mj(i, g-1, h+a[i]);
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio();
	cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for(int i=3; i<=n; i++)
	{
		mj(0, i, 0);
	}
	cout << cnt;
    return 0;
}
