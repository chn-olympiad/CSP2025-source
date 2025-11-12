#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	int a[n * m],c = 0,r = 0,R = 1;
	
	for(;c < (n * m); c++)
	{
		cin >> a[c];
		if(c < (n * m - 1))
		{
			a[c + 1] = a[c] - 1;
		}
		for(r = c;!(r == 0 or (a[r - 1] >= a[r]) and (a[r] >= a[r + 1]));r--)
		{
			if(R == r)
			{
				R++;
			}
			swap(a[r - 1],a[r]);
		}
	}
	c = ((R - 1) / n) + 1;
	if(R <= n)
	{
		r = R;
	}
	else if(((R - 1) / n) % 2)
	{
		r = n - (R % n) + 1;
	}
	else
	{
		r = (R - 1) % n;
	}
	
	cout << c << " " << r;
	
	return 0;
}
