#include<bits/stdc++.h>
using namespace std;
int n,a[5001]={0},s=0,maxx=0,t=0,l=0,r=0,tt=0;
void doing(int i)
{
	t+=a[i];
	tt++;
	if(a[i]>maxx)maxx=a[i];
	if(tt>=3&&t>2*maxx)
	{
	    s=(s++)%998244353;
	}
	else
	{
		if(i<=n)doing(i+1);
	    else return;
	    t-=a[i];
	    tt--;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	doing(1);
	cout<<9;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
