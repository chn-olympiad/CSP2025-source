#include<bits/stdc++.h>
using namespace std;
#define int long long
int read()
{
	int num = 0,f = 1;
	char c = getchar();
	while(!isdigit(c))
	{
		if(c == '-')
		{
			f = -1;
		}
		c = getchar();
	}
	while(isdigit(c))
	{
		num = num * 10 + (c - '0');
		c = getchar();
	}
	return num * f;
}
struct node
{
	int x,id;
} b[110000];
int a[110000][4];
bool cmp(node x,node y)
{
	return x.x > y.x;
}
bool cmpp(int x,int y)
{
	return x > y;
}
int f[110000];
int c[110000];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = read();
	while(T--)
	{
		int n = read();
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			a[i][1] = read();
			a[i][2] = read();
			a[i][3] = read();
			sum += a[i][1];
			f[i] = 1;
		}
		for(int i = 1;i <= n;i++)
		{
			b[i].x = a[i][2] - a[i][1];
			b[i].id = i;
		}
		sort(b + 1,b + n + 1,cmp);
		for(int i = 1;i <= n;i++)
		{
			if(b[i].x < 0)
			{
				break;
			}
			sum += b[i].x;
			f[b[i].id] = 2;
		}
		//cout << sum << endl;
		for(int i = 1;i <= n;i++)
		{
			//cout << f[i] << endl;
			b[i].x = a[i][3] - a[i][f[i]];
			b[i].id = i;
		}
		sort(b + 1,b + n + 1,cmp);
		for(int i = 1;i <= n;i++)
		{
			if(b[i].x < 0)
			{
				break;
			}
			sum += b[i].x;
			f[b[i].id] = 3;
		}
		int sum1 = 0,sum2 = 0,sum3 = 0;
		for(int i = 1;i <= n;i++)
		{
			if(f[i] == 1)
			{
				sum1++;
			}
			if(f[i] == 2)
			{
				sum2++;
			}
			if(f[i] == 3)
			{
				sum3++;
			}
		}
		int cur = 0;
		if(sum1 > n / 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(f[i] == 1)
				{
					cur++;
					c[cur] = max(a[i][2],a[i][3]) - a[i][1];
				}
			}
			sort(c + 1,c + cur + 1,cmpp);
			for(int i = 1;i <= sum1 - n / 2;i++)
			{
				sum += c[i];
			}
			cout << sum << endl;
		}
		else if(sum2 > n / 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(f[i] == 2)
				{
					cur++;
					c[cur] = max(a[i][1],a[i][3]) - a[i][2];
				}
			}
			sort(c + 1,c + cur + 1,cmpp);
			for(int i = 1;i <= sum2 - n / 2;i++)
			{
				sum += c[i];
			}
			cout << sum << endl;
		}
		else if(sum3 > n / 2)
		{
			for(int i = 1;i <= n;i++)
			{
				if(f[i] == 3)
				{
					cur++;
					c[cur] = max(a[i][2],a[i][1]) - a[i][3];
				}
			}
			sort(c + 1,c + cur + 1,cmpp);
			for(int i = 1;i <= sum3 - n / 2;i++)
			{
				sum += c[i];
			}
			cout << sum << endl;
		}
		else
		{
			cout << sum << endl;
		}
	}
	return 0;
}
