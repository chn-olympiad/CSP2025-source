#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll c[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ll a,b,sumx;
	cin>>a>>b;
	for(ll d=1;d<=a;d++)
	{
		for(ll e=1;e<=b;e++)
		{
			cin>>c[d][e];
			if(d==1 && e==1)
			{
				sumx=c[d][e];
			}
			
		}
	}
	ll sum,semf;
	for(ll d=1;d<=a-1;d++)
	{
		for(ll e=1;e<=b-1;e++)
		{
			if(c[d][e]<c[d][e+1])
			{
				sum=c[d][e];
				c[d][e]=c[d][e+1];
				c[d][e+1]=sum;
			}
			else if(c[d][e]<c[d+1][e])
			{
				sum=c[d][e];
				c[d][e]=c[d+1][e];
				c[d+1][e]=sum;
			}
				for(ll f=1;f<=a-1;f++)
	{
		for(ll g=1;g<=b-1;g++)
		{
			if(c[f][g]<c[f][g+1])
			{
				semf=c[f][g];
				c[f][g]=c[f][g+1];
				c[f][g+1]=sum;
			}
			else if(c[f][g]<c[f+1][g])
			{
				semf=c[f][g];
				c[f][g]=c[f+1][g];
				c[f+1][g]=semf;
			}
		}
	}
		}
	}
	
	for(ll f=1;f<=a;f++)
	{
		for(ll g=1;g<=b;g++)
		{
			
			if(c[f][g]==sumx)
			{
				cout<<g<<" "<<f;
				return 0;
			}
		}
	}
	
	return 0;
}
