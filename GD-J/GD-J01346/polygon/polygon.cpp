#include<bits/stdc++.h>
using namespace std;
int n,tt;
int ans1;
int a[5005],d[5005],b[5005];
map<int,int> k;
void js(int x,int y)
{
	if(x==y+1)
	{
		int ans=0,ma=-1e9;
		int t=0;
		for(int i=1; i<=x-1; i++)
		{
			ans+=d[i];
			ma=max(ma,d[i]);
			if(k[d[i]]>1) t++;
		}
		if(t<y&&ans>(2*ma))
		{
			tt=1;
			for(int i=1; i<=x-1; i++)
			{
//				cout<<d[i]<<" ";
				k[d[i]]++;
			}
//			cout<<endl;
			ans1++;
		}
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(b[i]!=1)
		{
			b[i]=1;
			d[x]=a[i];
			js(x+1,y);
			b[i]=0;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",&a[i]);
	}
//	js(1,a[1],1,0,a[1]);
	for(int i=3; i<=n; i++)
	{
		tt=0;
		k.clear();
		js(1,i);
	}
	printf("%d",ans1);
	return 0;
}
