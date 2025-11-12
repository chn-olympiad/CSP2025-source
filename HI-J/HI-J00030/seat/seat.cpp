#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m;
	int student[1145];
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>student[i];
	}
	int g=1,b=1;
	for (int i=2;i<=n*m;i++)
	{
		if (student[1]<student[i]&&b%2==1)
		{
			g++;
			if (g>n)
			{
				b++;
				g=n;
			}
		}
		else if (student[1]<student[i]&&b%2==0)
		{
			g--;
			if (g<1)
			{
				b++;
				g=1;
			}
		}
	}
	cout<<b<<" "<<g;
	return 0;
}

