#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,as[100001],bs[100001],cs[100001],x,y,z,out;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b;x=y=z=out=0;
		for(int j=1;j<=b;j++)
		{
			cin>>c>>d>>e;
			if(c>d&&c>e)as[++x]=min(c-d,c-e);
			else if(d>e)bs[++y]=min(d-c,d-e);
			else cs[++z]=min(e-c,e-d);
			out+=max(c,max(d,e));
		}
		if(x)sort(as+1,as+x+1);
		if(y)sort(bs+1,bs+y+1);
		if(z)sort(cs+1,cs+z+1);
		for(int j=1;j<=x-b/2;j++)
		{
			out-=as[j];
		}
		for(int j=1;j<=y-b/2;j++)
		{
			out-=bs[j];
		}
		for(int j=1;j<=z-b/2;j++)
		{
			out-=cs[j];
		}
		cout<<out<<'\n'; 
	}
	return 0;
}
