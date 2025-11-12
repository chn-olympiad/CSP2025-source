#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,ns=1,ms=1;
	int cj,a;
	cin>>n>>m;
	cin>>cj;
	for (int i=1;i<=n*m-1;i++)
	{
		cin>>a;
		if (a>cj)
		{
			if (ns%2==1)
			{
				if(ms<m)
				{
					ms++;
				}
				else
				{
					ns++;
				}
			}
			else
			{
				if(ms>1)
				{
					ms--;
				}
				else
				{
					ns++;
				}
			}
		}
	}
	cout<<ns<<' '<<ms;
	return 0;
}
