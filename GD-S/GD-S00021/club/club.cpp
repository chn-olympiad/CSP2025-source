#include<cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][5],x[100005],y[100005],z[100005],cx,cy,cz,cnt;
bool cmpx(long long u,long long v)
{
	return a[u][1]-max(a[u][2],a[u][3])>a[v][1]-max(a[v][2],a[v][3]);
}
bool cmpy(long long u,long long v)
{
	return a[u][2]-max(a[u][1],a[u][3])>a[v][2]-max(a[v][1],a[v][3]);
}
bool cmpz(long long u,long long v)
{
	return a[u][3]-max(a[u][1],a[u][2])>a[v][3]-max(a[v][1],a[v][2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cx=0,cy=0,cz=0,cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])cx++,x[cx]=i;
			else if(a[i][2]>a[i][3])cy++,y[cy]=i;
			else cz++,z[cz]=i;
		}
		if(cx>n/2)
		{
			sort(x+1,x+cx+1,cmpx);
			while(cx>n/2)
			{
				if(a[x[cx]][2]>a[x[cx]][3])cy++,y[cy]=x[cx],cx--;
				else cz++,z[cz]=x[cx],cx--;
			}
		}
		else if(cy>n/2)
		{
			sort(y+1,y+cy+1,cmpy);
			while(cy>n/2)
			{
				if(a[y[cy]][1]>a[y[cy]][3])cx++,x[cx]=y[cy],cy--;
				else cz++,z[cz]=y[cy],cy--;
			}
		}
		else if(cz>n/2)
		{
			sort(z+1,z+cz+1,cmpz);
			while(cz>n/2)
			{
				if(a[z[cz]][1]>a[z[cz]][2])cx++,x[cx]=z[cz],cz--;
				else cy++,y[cy]=z[cz],cz--;
			}
		}
		for(int i=1;i<=cx;i++)cnt+=a[x[i]][1];
		for(int i=1;i<=cy;i++)cnt+=a[y[i]][2];
		for(int i=1;i<=cz;i++)cnt+=a[z[i]][3];
		cout<<cnt<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
