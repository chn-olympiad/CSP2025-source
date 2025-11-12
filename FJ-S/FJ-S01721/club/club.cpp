#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],b[1000000],c[1000000],k;
long long d;
void p(int j1,int j2,int j3,int t,long long js)
{
	if(t==n+1)
	{
		d=max(d,js);
		return;
	}
	if(j1<n/2)
	{
		p(j1+1,j2,j3,t+1,js+a[t]);
	}
	if(j2<n/2)
	{
		p(j1,j2+1,j3,t+1,js+b[t]);
	}
	if(j3<n/2)
	{
		p(j1,j2,j3+1,t+1,js+c[t]);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>k;
	while(k--)
	{
		d=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i]>>c[i];
		}
		p(0,0,0,0,0);
		cout<<d<<endl;
	}
	
	return 0;
}
