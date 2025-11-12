#include <bits/stdc++.h>

using namespace std;
const int maxn = 104;
int n, m;
int bucket[maxn];
int r_score;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n*m;i++)
	{
		int t;
		scanf("%d", &t);
		if(i == 1) r_score = t;
		bucket[t] ++;
	}
	int rk = 0;
	for(int i=102;i>=0;i--)
	{
		rk += bucket[i];
		if(i == r_score) break;
	}
	// printf("r_score:%d, rk: %d\n", r_score, rk);
	// as far as I know, I am colGem !!!
	int r_colu = 1, r_line = 0, stat = 0;
	while(rk)
	{
		int delta = min(rk, n);
		rk -= delta;
		if(stat) r_line -= delta;
		else r_line += delta;
		if(rk > 0)
		{
			r_colu++;
			if(!stat) r_line = n+1;
			else r_line = 0;
			stat = !stat;
		}
	}
	printf("%d %d\n", r_colu, r_line);
	return 0;
}
 
