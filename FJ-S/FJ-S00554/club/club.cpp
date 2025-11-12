#include<iostream>
#include<algorithm>
using namespace std;

struct m
{
	int v;
	int a; 
};
struct a
{
	int v;
	int m;
};

int n;
int t;
int ans;
m mem[100005][4];
a a[3][100005];
bool vis[10005];

bool a(m x,m y)
{
	return x.v > y.v;
}
bool m(a x,a y)
{
	return x.v > y.v;
}


int main()
{
	cin >> t;
	while(t -- )
	{
		cin >> n;
		for(int i = 1;i <= n; i++ )
		{
			cin >> mem[i][0].v >> mem[i][1].v >> mem[i][2].v;
			a[1][i].v = mem[i][0].v;a[2][i].v = mem[i][2].v;a[3][i].v = mme[i][3].v;
		}
		sort()
		for(int i = 1;i <= 3;i ++ )
		{
			for(int i = 1;i <= n;i ++ )
			{
				if(a[])
			}
		}
	}
} 
