#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],t,t2[21],ta[21],tb[21],tans[21],d1=1,sum,sxor,used[500001],ans=0,pd=1;
int cf(int e)
{
	for(int i=1;i<=e;i++)
	{
		d1*=2;
	}
	return d1;
}
int turn(int c)
{
	t+=1;
	if(c==1){
		t2[t]=1;
		return 0;
	}
	if(c==0){
		t2[t]=0;
		return 0;
	}
	if(c%2==1) t2[t]=1;
	else t2[t]=0;
	turn(c/2);
	return 0;
};
int xor1(int a,int b)
{
	
	if(a==b) return 0;
	t=0;
	turn(a);
	for(int i=1;i<=t;i++)
	{
		ta[i]=t2[i];
	}
	t=0;
	turn(b);
	for(int i=1;i<=t;i++)
	{
		tb[i]=t2[i];
	}
	for(int i=1;i<=20;i++)
	{
		if(ta[i]==tb[i]) tans[i]=0;
		else tans[i]=1;
	}
	t=20;
	for(int i=20;i>=1;i--)
	{
		if(tans[i]==0) t-=1;
		else break;
	}
	sum=0;
	for(int i=0;i<t;i++)
	{
		d1=1;
		sum+=tans[i+1]*cf(i);
	}
	return sum;
};
int xor2(int a1,int b1)
{
	sxor=a[a1];
	for(int i=a1+1;i<=b1;i++)
	{
		sxor=xor1(sxor,a[i]);
	}
	return sxor;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		used[i]=1;
	}
	for(int dt=0;dt<n;dt++)
	{
		for(int cs=1;cs<=n-dt;cs++)
		{
			for(int i=cs;i<=cs+dt;i++)
			{
				if(used[i]==0) pd=0;
			}	
			if(pd==1)
			{
				if(xor2(cs,cs+dt)==k)
				{
					ans+=1;
					for(int i=cs;i<=cs+dt;i++)
					{
						used[i]=0;
					}
				}			
			}
			else pd=1;
		}
	}
	cout<<ans;
} 
