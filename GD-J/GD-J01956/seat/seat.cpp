#include <bits/stdc++.h>
using namespace std;
struct a{
	int j,y;
};
static bool cmp(a q,a p)
{
	return q.j>p.j;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m,num,da,an;
	cin>>n>>m;
	a z[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>z[i].j;
		z[i].y=i;
	}
	sort(z,z+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(z[i].y==0)
		{
			num=i+1;
			break;
		}
	}
	da=num/n;
	if(num%n!=0)
	{
		da++;
	}
	if(num/n%2==1)
	{
		an=n-num%n+1;
	}
	else
	{
		an=num%n;
	}
	cout<<da<<" "<<an;
	return 0;
}
