#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int lpos[11][11];
struct t{
	int pos,price;
};
t k[121];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,q=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>k[i].price;
		k[i].pos=i;
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
			if(k[i].price<k[j].price)
			{
				swap(k[i],k[j]);
			}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(k[q].pos==1)
			{
				cout<<j<<' '<<i;
				return 0;
			}
			q++;
		}
		j++;
		for(int i=n;i>=1;i--)
		{
			if(k[q].pos==1)
			{
				cout<<j<<' '<<i;
				return 0;
			}
			q++;
		}
	}
    return 0;
}

