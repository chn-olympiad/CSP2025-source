#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[220];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int pos=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(pos==a[i])
		{
			int lie=i/n;
			int hang=i%n;
			if(hang==0)
			{
				hang=n;
			}
			else
			{
				lie++;
			}
			if(lie%2==0)
			{
				cout<<lie<<' '<<n-hang+1;
				return 0;
			}
			else
			{
				cout<<lie<<' '<<hang;
				return 0;
			}
		}
	}
	return 0;
}



