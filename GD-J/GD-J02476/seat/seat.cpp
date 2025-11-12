#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

bool cmp(int a, int b)
{
	return a > b;
}

int n, m, sp, id;
int score[maxn * maxn];
int main()

{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	// n 一列几个，m 一行几个
	  
	for(int i = 1; i <= n * m; ++i) cin >> score[i];
	sp = score[1];
	sort(score + 1, score + n * m, cmp);
	
	for(int i = 1; i <= n * m; ++i)
	{
		if(score[i] == sp)
		{
			id = i;
		}
	}
	
	int hang, lie;
	
	if(id % n == 0)
	{
		lie = id / n;
		if(lie % 2 == 1)
		{
			cout << lie << " " << n;
			return 0;
		}
		else
		{
			cout << lie << " 1";
			return 0;
		}
	}
	else
	{
		lie = id / n + 1;
		int tmp = id - (lie - 1) * n;
		 
		if(lie % 2 == 1)
		{
			cout << lie << " " << tmp;
			return 0;
		}
		
		else
		{
			cout << lie << " " << n - tmp + 1;
			return 0;
		}
	}
	

	
	
	
	 
	return 0;
}
