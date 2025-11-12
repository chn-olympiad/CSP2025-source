#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 15;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m; // n = ÐÐ , m = ÁÐ 
	cin >> n >> m;
	int a[N * N] = {};
	int sct, pos;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	sct = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == sct)
		{
			pos = i;
			break;
		}
	}
	int lie, hang;
	lie = (ceil)((double)pos / n);
	hang = pos - (lie - 1) * n;
	if(lie % 2 == 0) hang = m - hang + 1;
	cout << lie << " " << hang << endl;
	return 0;
}
