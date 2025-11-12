# include <bits/stdc++.h>
using namespace std;

int a[105];

bool cmp(int x, int y)
{
	return x > y;
}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	int q = a[1];
	for(int i = 2; i <= n * m; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n * m + 1, cmp);
	int c = 0, r = 1;
	bool flag = 0;
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] != q)
		{
			if(flag == 0)
			{
				c++;
			}
			else
			{
				c--;
			}
			if(c > n)
			{
				c--;
				r++;
				flag = 1;
			}
			if(c < 1)
			{
				c++;
				r++;
				flag = 0;
			}
		}
		if(a[i] == q)
		{
			if(flag == 0)
			{
				c++;
			}
			else
			{
				c--;
			}
			if(c > n)
			{
				c--;
				r++;
				flag = 1;
			}
			if(c < 1)
			{
				c++;
				r++;
				flag = 0;
			}
			cout << r << " " << c;
			return 0;
		}
		// cout << a[i] << " " << c << " " << r << "change" << endl;
	}
	return 0;
}
