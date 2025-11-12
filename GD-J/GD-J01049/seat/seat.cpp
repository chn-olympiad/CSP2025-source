#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,c;
	cin >> n >> m;
	int a[n*m];
	for(int i=0;i<n*m;i++) cin >> a[i];
	x = a[0];
	for(int i=0;i<n*m;i++)
	{
		for(int o=0;o<n*m-i;o++)
		{
			if(a[o]<a[o+1])
			{
				c = a[o+1];
				a[o+1] = a[o];
				a[o] = c;
			}
		}
	}
	for(int i=0;i<m*n;i++)
	{
		if(a[i] == x)
		{
			if(i%n == 0)
			{
				if((i/n)%2 == 0) cout << i/n << ' ' << '1' << endl;
				else cout << i/n << ' ' << n << endl;
			}
			else
			{
				if(i/n%2 == 0) cout << i/n+1 << " " << i%n << endl;
				else cout << i/n+1 << ' ' << n+1-i%n << endl;
			}
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
