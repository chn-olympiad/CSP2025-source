#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, less<int> > p; 

int main()
{

	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[101];
	
	for(int i = 0; i < n*m; i++)
	{
		cin >> a[i];
		p.push(a[i]);
	}
	int R = a[0], r, c;
	
	for(int i = 1; i <= m; i++)
	{
		c = i;
		if(i % 2 != 0)
		{
			for(int j = 1; j <= n; j++)
			{
				r = j;
				if(p.top() != R) p.pop();
				else break;
			}
		}
		else
		{
			for(int j = n; j >= 1; j--)
			{
				r = j;
				if(p.top() != R) p.pop();
				else break;
			}
		}
		
	}
	cout << c << " " << r;

}