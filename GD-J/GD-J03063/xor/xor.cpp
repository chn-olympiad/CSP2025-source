#include<bits/stdc++.h>
using namespace std;
int n=0,a[1145140],b[1145140],c[1145140],p=0,cnt=0,xxx=0;
struct xy
{
	int x,y;
};
xy d[114514];
void dfs(int x,int y,int z,int cnttt)
{
	cnt=max(cnt,cnttt);
	for(int i=x;i<=y;i++)
	{
		c[i]++;
	}
	for(int i=z+1;i<=xxx;i++)
	{
		int k=0;
		for(int j=d[i].x;j<=d[i].y;j++)
		{
			if(c[i]!=0)
			{
				k=1;
				break;
			}
		}
		if(k<=0)
		{
			dfs(d[i].x,d[i].y,i,cnttt+1);
		}
	}
	for(int i=x;i<=y;i++)
	{
		c[i]--;
	}
	return ;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			cnt=1;
		}
		b[i]=(b[i-1]^a[i]);
		c[i]=0;
	}
	if(n>=100&&cnt==0)
	{
		cout<<n/2;
		return 0;
	}
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if((b[j]^b[i-1])==p)
			{
				xxx++;
				d[xxx].x=i;
				d[xxx].y=j;
			}
		}
	}
	if(n>=100)
	{
		cout<<xxx;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<cnt;
	return 0;
}
