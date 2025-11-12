#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,f,f1;
struct node
{
	int a,b,c,minn[4]={INT_MAX,INT_MAX,INT_MAX,INT_MAX};
}q[200005];
int cmp(node a,node b)
{
	if(a.minn[1]!=b.minn[1]) return a.minn[1]<b.minn[1];
	return a.minn[1]<b.minn[1];
}
int cmp1(node a,node b)
{
	if(a.minn[2]!=b.minn[2]) return a.minn[2]<b.minn[2];
	return a.minn[2]<b.minn[2];
}
int cmp2(node a,node b)
{
	if(a.minn[3]!=b.minn[3]) return a.minn[3]<b.minn[3];
	return a.minn[3]<b.minn[3];
}
int read()
{
	char c=getchar();
	if(!(c>='0'&&c<='9')) c=getchar();
	int x=c-'0';
	while(1)
	{
		c=getchar();
		if(c>='0'&&c<='9') x*=10,x+=(c-'0');
		else return x;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int sa=0,sb=0,sc=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			q[i].a=read(),q[i].b=read(),q[i].c=read();
			if(q[i].a>=q[i].b&&q[i].a>=q[i].c) sa++,ans+=q[i].a,f=1;
			else if(q[i].b>=q[i].a&&q[i].b>=q[i].c) sb++,ans+=q[i].b,f=2;
			else sc++,ans+=q[i].c,f=3;
			if(f==1) q[sa].minn[1]=min(q[i].a-q[i].b,q[i].a-q[i].c);
			if(f==2) q[sb].minn[2]=min(q[i].b-q[i].a,q[i].b-q[i].c);
			if(f==3) q[sc].minn[3]=min(q[i].c-q[i].a,q[i].c-q[i].b);
		}
		if(sa<=n/2&&sb<=n/2&&sc<=n/2) cout<<ans<<endl;
		else
		{
			if(sa>n/2)
			{
				sort(q+1,q+1+sa,cmp);
				for(int i=1;i<=sa-n/2;i++) ans-=q[i].minn[1];
			}
			if(sb>n/2)
			{
				sort(q+1,q+1+sb,cmp1);
				for(int i=1;i<=sb-n/2;i++) ans-=q[i].minn[2];
			}
			if(sc>n/2)
			{
				sort(q+1,q+1+sc,cmp2);
				for(int i=1;i<=sc-n/2;i++) ans-=q[i].minn[3];
			}
			cout<<ans<<endl;
		}
	}
}
