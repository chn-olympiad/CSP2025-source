#include <bits/stdc++.h>
using namespace std;
const int N = 10 , M = 105;
bool flag = false;
int n , m , num[N][N] , a , cnt , p;
vector <int> v;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cnt = n * m - 1;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cin >> a;
			if(!flag)
			{
				p = a;
				flag = 1;
			}
			v.push_back(a);
		}
	}
	sort(v.begin(),v.end());
	for(int i = 1;i <= m;i++)
	{
		if(i % 2 == 1)
		{
			for(int j = 1;j <= n;j++)
			{
				if(v[cnt--] == p)
				{
					cout << i << ' ' << j;
				}
			}
		}
		else
		{
			
			for(int j = n;j >= 1;j--)
			{
				if(v[cnt--] == p)
				{
					cout << i << ' ' << j;
				}
			}
		}
	}
	return 0;
}
