//GZ-S00212 贵阳市南明区华麟学校 李俊熠 
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int T,n;
struct Stu
{
	int x,y,z,mx; 
}a[N];
int reP(int x,int m1,int m2,int m3)
{
	if(a[x].mx==1) 
	{
		if(m1>0) return a[x].x;
		else
		{
			if(m2>0 && a[x].y>a[x].z) return a[x].y;
			else return a[x].z;
		}
	}
	if(a[x].mx==2) 
	{
		if(m2>0) return a[x].y;
		else
		{
			if(m3>0 && a[x].z>a[x].x) return a[x].z;
			else return a[x].x;
		}
	}
	if(a[x].mx==3) 
	{
		if(m3>0) return a[x].z;
		else
		{
			if(m1>0 && a[x].x>a[x].y) return a[x].x;
			else return a[x].y;
		}
	}
}
int dfs(int x,int m1,int m2,int m3,int pl)
{
	int re=0,dre1=0,dre2=0,dre3=0;
	if(x==n)
	{
		return pl+reP(x,m1,m2,m3);
	}
	if(m1>0)
	{
		dre1=dfs(x+1,m1-1,m2,m3,pl+a[x].x);
	}
	if(m2>0)
	{
		dre2=dfs(x+1,m1,m2-1,m3,pl+a[x].y);
	}
	if(m3>0)
	{
		dre3=dfs(x+1,m1,m2,m3-1,pl+a[x].z);
	}
	re=max(dre1,max(dre2,dre3));
	return re;
}
bool cmp1(Stu a,Stu b)
{
	return a.x>b.x;
}
int main()
{
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int mx1=0,mx2=0,mx3=0,m2,m3,s23=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y>>a[i].z; 
			m2=a[i].y,m3=a[i].z;
			if(s23)	if(m2!=0 || m3!=0) s23=0;
			if(a[i].x>a[i].y && a[i].x>a[i].z) mx1+=a[i].x,a[i].mx=1;
			else if(a[i].y>a[i].x && a[i].y>a[i].z) mx2+=a[i].y,a[i].mx=2;
			else if(a[i].z>a[i].y && a[i].z>a[i].x) mx3+=a[i].z,a[i].mx=3;
		}
		if(s23 && m2==0 && m3==0)
		{
			sort(a+1,a+n+1,cmp1);
			int ans=0,n2=n/2;
			for(int i=1;i<=n2;i++) ans+=a[i].x;
			cout<<ans<<endl;
		}
		else cout<<dfs(1,n/2,n/2,n/2,0)<<endl;
	}
	return 0;
}
