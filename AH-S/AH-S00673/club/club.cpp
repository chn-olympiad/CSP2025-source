#include <bits/stdc++.h>
using namespace std;
int n;
struct myd
{
	int m1,m2,m3,gl;
}m[100005],m1[100005];
bool cmp(myd a,myd b)
{
	if(a.m1!=b.m1)
	{
		return a.m1>b.m1;
	}else if(a.m2!=b.m2)
	{
		return a.m2>b.m2;
	}else{
		return a.m3>b.m3;
	}
}
bool cmp2(myd a,myd b)
{
	return a.m2>b.m2;
}
bool cmp3(myd a,myd b)
{
	return a.m3>b.m3;
}
bool cmp1(myd a,myd b)
{
	return a.m1>b.m1;
}
int maxm(myd m)
{
	if(m.m1>m.m2 && m.m1>m.m3)
		return m.m1;
	if(m.m2>m.m1 && m.m2>m.m3)
		return m.m2;
	if(m.m3>m.m2 && m.m3>m.m1)
		return m.m3;
	if(m.m1==m.m2)
		return max(m.m1,m.m3);
	if(m.m2==m.m3 or m.m1==m.m3)
		return max(m.m1,m.m2);
}
void fcl()
{
	for(int i=1;i<=n;i++)
	{
		m1[i].m3=m[i].m3;
		m1[i].m2=m[i].m2;
		m1[i].m1=m[i].m1;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int mem_1=0,mem_2=0,mem_3=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].m1>>m[i].m2>>m[i].m3;
		}
		for(int i=1;i<=n;i++)
		{
			if(maxm(m[i])==m[i].m1)
			{
				mem_1++;
				sum+=m[i].m1;
				m[i].gl=1;
			}
			if(maxm(m[i])==m[i].m2)
			{
				mem_2++;
				sum+=m[i].m2;
				m[i].gl=2;
			}
			if(maxm(m[i])==m[i].m3)
			{
				mem_3++;
				sum+=m[i].m3;
				m[i].gl=3;
			}
		}
		cout<<sum<<endl;
		if(mem_1>=n/2)
		{
			fcl();
			if(mem_2>mem_3)
			{
				sort(m1,m1+n+1,cmp3);
				for(int i=1;i<=mem_1-n;i++)
				{
					sum-=m1[i].m1;sum+=m1[i].m3;
					mem_1--;mem_3++;
				}
			}else{
				sort(m1,m1+n+1,cmp2);
				for(int i=1;i<=mem_1-n;i++)
				{
					sum-=m1[i].m1;sum+=m1[i].m2;
					mem_1--;mem_2++;
				}
			}
		}
		if(mem_2>=n/2)
		{
			fcl();
			if(mem_1>mem_3)
			{
				sort(m1,m1+n+1,cmp3);
				for(int i=1;i<=mem_2-n;i++)
				{
					sum-=m1[i].m2;sum+=m1[i].m3;
					mem_2--;mem_3++;
				}
			}else{
				sort(m1,m1+n+1,cmp1);
				for(int i=1;i<=mem_2-n;i++)
				{
					sum-=m1[i].m2;sum+=m1[i].m1;
					mem_2--;mem_1++;
				}
			}
		}
		if(mem_3>=n/2)
		{
			fcl();
			if(mem_1>mem_2)
			{
				sort(m1,m1+n+1,cmp2);
				for(int i=1;i<=mem_3-n;i++)
				{
					sum-=m1[i].m3;sum+=m1[i].m2;
					mem_3--;mem_2++;
				}
			}else{
				sort(m1,m1+n+1,cmp1);
				for(int i=1;i<=mem_3-n;i++)
				{
					sum-=m1[i].m3;sum+=m1[i].m1;
					mem_3--;mem_1++;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			m[i]={0,0,0,0};
		}
	}
}
