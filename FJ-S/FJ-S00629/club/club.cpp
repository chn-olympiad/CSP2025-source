#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int club[5], ans, T, n;
int sum;

struct STU
{
	int a, b, c;
}t[N];

void dfs(int x)
{
	if(x == n + 1) 
	{
		ans = max(ans, sum);
		//for(int i =1; i <= 3; i++)
		//	cout << club[i] << ' ';
	//	cout << endl;
		return;
	}
	
	if(club[1] < (n / 2)) 
	{
		sum += t[x].a;
		club[1] ++;
		dfs(x + 1);sum -= t[x].a; club[1] --;
	}
	
	
	
	if(club[2] < (n / 2))
	{
		sum += t[x].b;
		club[2] ++;
		dfs(x + 1);sum -= t[x].b; club[2] --;
	}
	
	
	
	if(club[3] < (n / 2))
	{
		sum += t[x].c;
		club[3] ++;
		dfs(x + 1);sum -= t[x].c; club[3] --;
	}
	
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &T);
	while(T --)
	{
		ans = 0; sum = 0; memset(club, 0, sizeof club);
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			t[i] = {x, y, z};
		}
		
		dfs(1);
		
		printf("%d\n", ans);
	}
	return 0;
}
