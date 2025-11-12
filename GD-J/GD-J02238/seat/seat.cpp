#include<bits/stdc++.h>
using namespace std;

int n, m, c, r, ran;

struct seat
{
	int num, score;
}a[110];

bool cmp(seat a, seat b)
{
	return a.score > b.score;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
	
	cin >> n >> m;
	
	for(int i = 1;i <= n * m;i ++)
	{
		cin >> a[i].score;
		a[i].num = i;
	}
	
	sort(a + 1, a + 1 + n * m, cmp);
	
	for(int i = 1;i <= n * m;i ++)
	{
		if(a[i].num == 1)
		{
			ran = i;
			break;
		}
	}
	
	r = ran / n;
	
	if(ran % n == 0)
	{
		if(r % 2 == 1)
		{
			cout << r << ' ' << n;
		}
		else cout << r << ' ' << 1;
	}
	else 
	{
		if(r % 2 == 0)
		{
			c = ran - r * n;
		}
		else{
			c = n - (ran - r * n) + 1;
		}
		cout << r + 1 << ' ' << c;
	}
	
	fclose(stdin), fclose(stdout);
	
	return 0;
}
