#include <iostream>
#include <cstdio>
using namespace std;
string s;
int a[105],n,m,k,ni=1,mi=1,o,l=0;
int main()
{
	freopen("seat3.in","r",stdin);
	freopen("seat3.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>k;
		if(i==1) o=k;
		a[k]++;
	}
	
	for(int i=100;i>=1;i--)
	{	
		if(i==o)
		{
			cout<<mi<<" "<<ni;
			break;
		}
		if(a[i]==1&&l==0)
		{
			ni++;
			if(ni>n)
			{
				mi++;
				ni=n;
				l=1;
				continue;
			}
		}
		if(a[i]==1&&l==1)
		{
			ni--;
			if(ni<1)
			{
				mi++;
				ni=1;
				l=0;
				continue;
			}
		}
		
		
	}
	
}