#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, a[101], i = 1, j = 1, idx = 1;
	bool down = true;
	
	cin >> n >> m;
	for(int i = 1; i <= n*m; i++)
		cin >> a[i];
		
	int target = a[1];
	sort(a+1, a+n*m+1, cmp);
	
	while(a[idx] != target)
	{
		if(j == 1 and not down)
		{
			i++;
			down = true;
		}
		else if(j == n and down)
		{
			i++;
			down = false;
		}
		else
		{
			if(down)
				j++;
			else
				j--;
		}
		idx++;
	}
	cout << i << " " << j;
	return 0;
}
