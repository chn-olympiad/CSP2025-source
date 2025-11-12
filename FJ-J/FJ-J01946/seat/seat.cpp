#include <bits/stdc++.h>
using namespace std;
struct ID
{
	int num;
	int id;
}a[105];
bool cmp(ID x,ID y)
{
	return x.num>y.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			if(i%n==0||i%n==1)
			{
				if(i/n%2==0)
				{
					if(i%n==0)
					{
						cout<<i/n<<" "<<i;
					}
					else
					{
						cout<<i/n+1<<" "<<i;
					}
				}
				else
				{
					if(i%n==0)
					{
						cout<<i/n<<" "<<n;
					}
					else
					{
						cout<<i/n+1<<" "<<n;
					}
				}
			}
			else
			{
				if(i/n%2==1)
				{
					cout<<1+i/n<<" "<<i%n;
				}
				else
				{
					cout<<1+i/n<<" "<<2;
				}
			}
		}
	}
	return 0; 
} 
