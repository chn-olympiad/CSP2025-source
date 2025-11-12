#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int w = 1,f = 0;
	char c = getchar();
	while(c < '0' or c > '9'){if(c == '-') w = -1;c = getchar();}
	while(c >= '0' and c <= '9') f = f * 10 + c - '0',c = getchar();
	return w * f; 
}

const int _ = 1e5 + 5;

int T,n,ans;
int a[_][4];
int mx[_];
int num[4];
priority_queue <int> q;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T = read();
	while(T--)
	{
		while(!q.empty()) q.pop();
		memset(mx,0,sizeof mx);
		memset(num,0,sizeof num);
		
		n = read();
		ans = 0;
		for(int i = 1;i <= n;i++)
		{
			int _max = 0,t = 1;
			for(int j = 1;j <= 3;j++)
			{
				a[i][j] = read();
				if(a[i][j] > _max)
					t = j,_max = a[i][j]; 
			}
			mx[i] = t;
			num[t]++;
			ans += _max;
		}
		int t = 1,t2,t3;
		for(int i = 1;i <= 3;i++)
			if(num[i] > num[t]) t = i;
		if(t == 1) t2 = 2,t3 = 3;
		if(t == 2) t2 = 1,t3 = 3;
		if(t == 3) t2 = 1,t3 = 2;
		for(int i = 1;i <= n;i++)
		{
			if(mx[i] != t) continue;
			q.push(max(a[i][t2],a[i][t3]) - a[i][t]);
		}
		for(int i = 1;i <= num[t] - n / 2;i++)
		{
			ans += q.top();
			q.pop();
		}
		cout << ans << endl;
	}
	return 0;
}
