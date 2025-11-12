#include<iostream> 
#include<cstdio> 
#include<cmath> 
#include<string.h>
using namespace std;
int a[500010],maxx=-1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,t,s;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		s=0,t=0;
		for(int j=i;j<=n;j++)
		{
			t=t^a[j];
			if(t==k)
			{
				s++;
				t=0;
			}
		}
		maxx=max(maxx,s);
	}
	cout<<maxx;
	return 0;
} 
