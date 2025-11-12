#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m,a,b,c;
	cin >> n >> m;
	for(int i = 1;i <= n* m;i++)
	{
		cin >> c;
		if(a > n)
		{
			c = 1;
			a--;
			b++;
		}
		if(a < 1)
		{
			c = 1;
			a++;
			b--;
		}
		if(b > m)
		{
			c = i;
		    a--;
		    b++;
		}
		if(b < 1) 
		{
			c = i;
			a++;
			b--;
		}
	}
	cout << a << " " << b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
