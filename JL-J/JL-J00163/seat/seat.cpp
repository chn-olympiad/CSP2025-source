#include <bits/stdc++.h>
using namespace std;
int n, m;
struct seats
{
	int score;
	bool isone;
};
bool cmp(seats x, seats y)
{
	return x.score>y.score;
}

seats b[15*15];
int main()
{
	freopen("seat.int", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	b[1].isone=1;
	for(int i=1;i<=m*n;i++)
	{
		cin >> b[i].score;
	}
	sort(b+1, b+m*n+1, cmp);
	for(int i=1;i<=m*n;i++)
	{
		if(b[i].isone)
		{
			int c = i/n;//lie
			int r = i % n;//hang
			if(r==0)
			{
				if(c%2!=0) r = n;
				else r = 1;
				cout << c << " " << r;
				break;
			}
			if(c%2!=0) r = n+1 - r;
			c++;
			cout << c << " " << r;
			break;
		}
	}
	return 0;
}
