#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,t,k,s;
int x[1000005],y[1000005],z[1000005];
int max1(int m,int n,int q)
{
	int s=max(n,m);
	s=max(s,q);
	return s;
}
void d(int a,int b,int c)
{
	int o=max1(a,b,c);
	int xx=0;
	if(a==o&&a<=k)
	{
		d(a+1,b,c);
		s+=o;
	}
	else if(a==o&&a>=k)
	{
		int xx=max(b,c);
		if(b==xx&&b<=k)
		{
			d(a,b+1,c);
			s+=b;
		}
		else
		{
			d(a,b,c+1);
			s+=c;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int abc[t+5],s1=1;
	while(t--)
	{
		cin>>n;
		k=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>z[i];
		}
		for(int i=1;i<=n;i++)
		{
			d(z[i],y[i],z[i]);
			
		}
		abc[s1]=s;
		s1++;
	}
	for(int i=1;i<s1;i++)
	{
		cout<<abc[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
