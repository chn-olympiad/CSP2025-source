#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

ll seat[150];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	ll sum = (ll)n * m;
	for(ll i = 1; i <= sum; i++)
	{
		scanf("%lld", &seat[i]);
	}
	ll find = seat[1];
	sort(seat + 1, seat + sum + 1, cmp);
	ll t = -1;
	for(int i = 1; i <= sum; i++)
	{
		if(seat[i] == find)
		{
			t = i;
			break;
		}
	}
	int times = t / n, more = t % n;
	if(more == 0)
	{
		if(times % 2 == 0) printf("%d %d\n", times, 1);
		else printf("%d %d\n", times, n);
		return 0;
	}
	if(times % 2 == 0)
	{
		printf("%d %d\n", times + 1, more);
	}
	else
	{
		printf("%d %d\n", times + 1, n - more + 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
