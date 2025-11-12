#include <bits/stdc++.h>
using namespace std;
const int siz=1e5+10;
int a[siz];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	k=a[1];sort(a+1,a+n*m+1,greater<int>());
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
		{
			for(int j=1;j<=m;j++)
				if(k==a[++cnt])
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
		}
		else
		{ 
			for(int j=m;j>=1;j--)
				if(k==a[++cnt])
				{
					cout<<i<<' '<<j<<'\n';
					return 0;
				}
		}
	}
	return 0;
}
//Finish debug on 9:12.