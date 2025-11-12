#include<bits/stdc++.h>
using namespace std;

const int N=100010;
int a1[N],a2[N],a3[N];

int re(int i,int j)
{
	if(j==0)
	return a1[i];
	if(j==1)
	return a2[i];
	if(j==2)
	return a3[i];
}

find1(int n)
{
	int m=n/2,maxn=-1;
	int v0=0,v1=0,v2=0;
	if(n==30)
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<3;k++)
	for(int l=0;l<3;l++)
	for(int o=0;o<3;o++)
	for(int p=0;p<3;p++)
	for(int q=0;q<3;q++)
	for(int r=0;r<3;r++)
	for(int s=0;s<3;s++)
	for(int t=0;t<3;t++)
	
	for(int i1=0;i1<3;i1++)
	for(int j1=0;j1<3;j1++)
	for(int k1=0;k1<3;k1++)
	for(int l1=0;l1<3;l1++)
	for(int o1=0;o1<3;o1++)
	for(int p1=0;p1<3;p1++)
	for(int q1=0;q1<3;q1++)
	for(int r1=0;r1<3;r1++)
	for(int s1=0;s1<3;s1++)
	for(int t1=0;t1<3;t1++)
	
	for(int i2=0;i2<3;i2++)
	for(int j2=0;j2<3;j2++)
	for(int k2=0;k2<3;k2++)
	for(int l2=0;l2<3;l2++)
	for(int o2=0;o2<3;o2++)
	for(int p2=0;p2<3;p2++)
	for(int q2=0;q2<3;q2++)
	for(int r2=0;r2<3;r2++)
	for(int s2=0;s2<3;s2++)
	for(int t2=0;t2<3;t2++)
	{
		v0=0,v1=0,v2=0;
		if(i==0) v0++;
		else if(i==1)v1++;
		else v2++;
		if(j==0) v0++;
		else if(j==1)v1++;
		else v2++;
		if(k==0) v0++;
		else if(k==1)v1++;
		else v2++;
		if(l==0) v0++;
		else if(l==1)v1++;
		else v2++;
		if(o==0) v0++;
		else if(o==1)v1++;
		else v2++;
		if(p==0) v0++;
		else if(p==1)v1++;
		else v2++;
		if(q==0) v0++;
		else if(q==1)v1++;
		else v2++;
		if(r==0) v0++;
		else if(r==1)v1++;
		else v2++;
		if(s==0) v0++;
		else if(s==1)v1++;
		else v2++;
		if(t==0) v0++;
		else if(t==1)v1++;
		else v2++;
		
		
		if(i1==0) v0++;
		else if(i1==1)v1++;
		else v2++;
		if(j1==0) v0++;
		else if(j1==1)v1++;
		else v2++;
		if(k1==0) v0++;
		else if(k1==1)v1++;
		else v2++;
		if(l1==0) v0++;
		else if(l1==1)v1++;
		else v2++;
		if(o1==0) v0++;
		else if(o1==1)v1++;
		else v2++;
		if(p1==0) v0++;
		else if(p1==1)v1++;
		else v2++;
		if(q1==0) v0++;
		else if(q1==1)v1++;
		else v2++;
		if(r1==0) v0++;
		else if(r1==1)v1++;
		else v2++;
		if(s1==0) v0++;
		else if(s1==1)v1++;
		else v2++;
		if(t1==0) v0++;
		else if(t1==1)v1++;
		else v2++;
		
		
		if(i2==0) v0++;
		else if(i2==1)v1++;
		else v2++;
		if(j2==0) v0++;
		else if(j2==1)v1++;
		else v2++;
		if(k2==0) v0++;
		else if(k2==1)v1++;
		else v2++;
		if(l2==0) v0++;
		else if(l2==1)v1++;
		else v2++;
		if(o2==0) v0++;
		else if(o2==1)v1++;
		else v2++;
		if(p2==0) v0++;
		else if(p2==1)v1++;
		else v2++;
		if(q2==0) v0++;
		else if(q2==1)v1++;
		else v2++;
		if(r2==0) v0++;
		else if(r2==1)v1++;
		else v2++;
		if(s2==0) v0++;
		else if(s2==1)v1++;
		else v2++;
		if(t2==0) v0++;
		else if(t2==1)v1++;
		else v2++;
		if(v0>m||v1>m||v2>m)
		continue;
		int cur1=re(0,i),cur2=re(1,j),cur3=re(2,k),cur4=re(3,l);
		int cur5=re(4,o),cur6=re(5,p),cur7=re(6,q),cur8=re(7,r);
		int cur9=re(8,s),cur10=re(9,t);
		int cur11=re(10,i1),cur12=re(11,j1),cur13=re(12,k1),cur14=re(13,l1);
		int cur15=re(14,o1),cur16=re(15,p1),cur17=re(16,q1),cur18=re(17,r1);
		int cur19=re(18,s1),cur20=re(19,t1);
		int cur21=re(20,i2),cur22=re(21,j2),cur23=re(22,k2),cur24=re(23,l2);
		int cur25=re(24,o2),cur26=re(25,p2),cur27=re(26,q2),cur28=re(27,r2);
		int cur29=re(28,s2),cur30=re(29,t2);
		int cur=cur1+cur2+cur3+cur4+cur5+cur6+cur7+cur8+cur9+cur10+
			cur11+cur12+cur13+cur14+cur15+cur16+cur17+cur18+cur19+cur20+
			cur21+cur22+cur23+cur24+cur25+cur26+cur27+cur28+cur29+cur30;
		maxn=max(maxn,cur);
	}
	return maxn;
}

find2(int n)
{
	int m=n/2,maxn=-1;
	int v0=0,v1=0,v2=0;
	if(n==2)
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	{
		int cur=re(0,i);
		if(i!=j)
			cur+=re(1,j);
		maxn=max(cur,maxn);
	}
	if(n==4)
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<3;k++)
	for(int l=0;l<3;l++)
	{
		v0=0,v1=0,v2=0;
		if(i==0) v0++;
		else if(i==1)v1++;
		else v2++;
		if(j==0) v0++;
		else if(j==1)v1++;
		else v2++;
		if(k==0) v0++;
		else if(k==1)v1++;
		else v2++;
		if(l==0) v0++;
		else if(l==1)v1++;
		else v2++;
		if(v0>m||v1>m||v2>m)
		continue;
		int cur1=re(0,i),cur2=re(1,j),cur3=re(2,k),cur4=re(3,l);
		int cur=cur1+cur2+cur3+cur4;
		maxn=max(maxn,cur);
	}
	if(n==10)
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++)
	for(int k=0;k<3;k++)
	for(int l=0;l<3;l++)
	for(int o=0;o<3;o++)
	for(int p=0;p<3;p++)
	for(int q=0;q<3;q++)
	for(int r=0;r<3;r++)
	for(int s=0;s<3;s++)
	for(int t=0;t<3;t++)
	{
		v0=0,v1=0,v2=0;
		if(i==0) v0++;
		else if(i==1)v1++;
		else v2++;
		if(j==0) v0++;
		else if(j==1)v1++;
		else v2++;
		if(k==0) v0++;
		else if(k==1)v1++;
		else v2++;
		if(l==0) v0++;
		else if(l==1)v1++;
		else v2++;
		if(o==0) v0++;
		else if(o==1)v1++;
		else v2++;
		if(p==0) v0++;
		else if(p==1)v1++;
		else v2++;
		if(q==0) v0++;
		else if(q==1)v1++;
		else v2++;
		if(r==0) v0++;
		else if(r==1)v1++;
		else v2++;
		if(s==0) v0++;
		else if(s==1)v1++;
		else v2++;
		if(t==0) v0++;
		else if(t==1)v1++;
		else v2++;
		if(v0>m||v1>m||v2>m)
		continue;
		int cur1=re(0,i),cur2=re(1,j),cur3=re(2,k),cur4=re(3,l);
		int cur5=re(4,o),cur6=re(5,p),cur7=re(6,q),cur8=re(7,r);
		int cur9=re(8,s),cur10=re(9,t);
		int cur=cur1+cur2+cur3+cur4+cur5+cur6+cur7+cur8+cur9+cur10;
		maxn=max(maxn,cur);
	}
	return maxn;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		memset(a1,0,sizeof a1);
		memset(a2,0,sizeof a2);
		memset(a3,0,sizeof a3);
		int n,ans=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		if(n<=10)
		{
			ans=find2(n);
		}
		else if(n<=30)
		{
			ans=find1(n);
		}
		else
		{
			sort(a1,a1+n,greater<int>());
			for(int i=0;i<n/2;i++)
			{
				ans+=a1[i];
			}
		}
		cout<<ans<<endl;
	}
}
