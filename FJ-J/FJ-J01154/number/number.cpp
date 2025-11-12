#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
ll c[100000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	ll d=0;
	cin>>a;
	for(ll b=0;b<a.size();b++)
	{
		if((a[b]-'0'>=0 && a[b]-'0'<=9))
		{
			c[d]=a[b]-'0';
			d++;
		}
	}
	ll sum=0,semk=0;
	for(ll e=0;e<d-1;e++)
	{
		if(c[e]<c[e+1])
		{
			sum=c[e];
			c[e]=c[e+1];
			c[e+1]=sum;
		}
				for(ll t=0;t<d-1;t++)
				{
					if(c[t]<c[t+1])
				{
						semk=c[t];
						c[t]=c[t+1];
						c[t+1]=semk;
					}
	}
	}

	for(ll o=0;o<d;o++)
	{
		cout<<c[o];
	}
	
	return 0;
}
