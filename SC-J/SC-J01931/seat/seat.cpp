#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,c = 1,r = 1;
	bool flag = true;
	cin >> n >> m >> p;
	vector<int> g(n*m+1);
	g.push_back(p);
	for (int i = 1;i < n*m;i++)
	{
		int a;	
		cin >> a;
		g.push_back(a);
	}
	sort(g.begin(),g.end()+1,cmp);
	for (int i = 0;i < n*m;i++)
	{
		if (g[i] == p)
		{
			cout << c << " " << r;
			break;
		}
		else if (flag)
		{
			if (r >= n)
			{
				c++;
				flag = false;
			}
			else
			{
				r++;
			}
		}
		else
		{
			if (r <= 1)
			{
				c++;
				flag = true;
			}
			else
			{
				r--;
			}
		}
	}
	return 0;
} 