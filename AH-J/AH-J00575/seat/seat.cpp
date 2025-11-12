#include<bits/stdc++.h>
using namespace std;
struct se{
	int cj,h;
}a[109];
bool cmp(se x,se y)
{
	return x.cj>y.cj;
}
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].cj;
		if(i==1)
		{
			a[i].h=1;
		}
		else{
			a[i].h=0;
		}
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].h==1)
		{
			int o=0,p=0;
			if(i%n!=0)
			{
				o=1;
			}
			if(i%n==0)
			{
				p=n;
			}
			if((i/n+o)%2!=0)
			{
				cout<<i/n+o<<" "<<i%n+p;
			}
			else
			{
				cout<<i/n+o<<" "<<n-(i%n+p)+1;
			}
			return 0;
		}
	}
}
