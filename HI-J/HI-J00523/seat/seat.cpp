#include<bits/stdc++.h>

int num_cnt[10 + '0'];

void run()
{
	int n, m;
	std::cin >> n >> m;
	
	int a = 0;
	std::cin >> a;
	int cnt = 1;
	for(int i = 1; i < n * m; ++i)
	{
		int x;
		std::cin >> x;
		//printf("%d ", x);
		if(x > a)
		{
			cnt += 1;
		}
	}
	//printf("%d ", cnt);
	
	int line = (cnt - 1) / n + 1;
	int row = (cnt) % n;
	if(row == 0)
	{
		row = n;
	}
	if(line % 2 == 0)
	{
		row = n - row + 1;
	}
	printf("%d %d", line, row);
	
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	std::ios::sync_with_stdio(0);
	run();
	return 0;
}

