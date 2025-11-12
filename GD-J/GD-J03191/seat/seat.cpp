#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin >> n >> m;
	for(int i = 1;i <= (n*m);i++)
	{
		cin >> a[i];
	}
	int z = a[1];
	int b = 0;
	while(b == 0)
	{
		int c = 1;
		while(c != (n*m))
		{
			if(a[c] < a[c+1])
			{
				int t = a[c];
				a[c] = a[c+1];
				a[c+1] = t;
				b = 1;
			}
			c++;
		}
    }
	int i = 1,h = 1,l = 1;
	while(a[i] != z)
	{
		if(l % 2 == 1)
		{
			if(h == n)
			{
				l++;
			}
			else
			{
				h++;
			}
		}
		else
		{
			if(h == 1)
			{
				l++;
			}
			else
			{
				h--;
			}
		}
	}
	cout << l << " ";
	cout << h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
