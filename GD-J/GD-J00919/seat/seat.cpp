#include<bits/stdc++.h>
using namespace std;
struct xinxi
{
	int sco,pm;
}cs[105];
int n,m,R,am,an,r;
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>cs[i].sco;

	}
    r=cs[0].sco;
	for(int i=0;i<n*m;i++)
	{
		for(int j=0;j<n*m-i-1;j++)
		{
			if(cs[j].sco<cs[j+1].sco)
			{
				cs[104]=cs[j];
				cs[j]=cs[j+1];
				cs[j+1]=cs[104];
			}
		}
	}
	for(int i=0;i<n*m;i++)
	{
		cs[i].pm=i+1;
		if(cs[i].sco==r) R=cs[i].pm;
	}
	if((R/n)%2==0||((R/n)%2==1&&R%n==0))
	{
		if((R/n)%2==0)
		{
			am=(R/n==0?R/n+1:R/n)*2-1;
		    an=R%n;
		}
		else 
		{
			am=(R/n==1?R/n:R/n-1)*2-1;
			an=n;
		}
	}
	else
	{
		if((R/n)%2==1)
		{
			am=R/n+1;
			an=n-(R%n)+1;
		}
		else
		{
			am=(R/n-1)+1;
			an=1;
		}
	}
	cout<<am<<" "<<an;
	return 0;
}
