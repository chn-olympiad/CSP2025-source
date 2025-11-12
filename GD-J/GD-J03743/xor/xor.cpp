#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],s[25][500005],l,t[25];
bool pA=1,pB=1;
struct node
{
	int x,y;
}b[10000005];
bool cmp(node a,node b)
{
	if(a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) pA=0;
		if(a[i]>1) pB=0;
	}
	if(pA==1 && k==0) 
	{
		cout<<n/2;
		return 0;
	}
	else if(pB==1 && k<=1)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0) l++;
				else if(a[i]==a[i+1]) l++,i++; 
			}
		}
		else if(k==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==1) l++; 
			}
		}
		cout<<l;
		return 0;
	}
	else if(n<=500000)
	{
		for(int i=1;i<=n;i++)
		{
			int t=0;
			for(int j=i;j<=n;j++)
			{
				if((t^a[j])==k) b[++l].x=i,b[l].y=j;
				t=t^a[j];
			}
		}
		sort(b+1,b+1+l,cmp);
		int y=0,s=0;
		for(int i=1;i<=l;i++)
		{
			if(b[i].x>y) y=b[i].y,s++;
			//cout<<i<<" "<<s<<" "<<b[i].x<<" "<<b[i].y<<" "<<y<<endl;
		}
		cout<<s;
		return 0;
	}/*
	int x=k,t1=0; 
	while(x!=0)
	{
		t[t1]+=x&1;
		x>>=1;
		t1++;
	}
	for(int i=1;i<=n;i++)
	{
		int x=a[i],t=0;
		if(a[i]==k) 
		{
			l++;
			continue;
		}
		if(a[i-1]!=k)
		{
			for(int j=0;j<=20;j++)
			{
				s[j][i]=s[j][i-1];
			}
		}
		while(x!=0)
		{
			s[t][i]+=x&1;
			x>>=1;
			t++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k) continue;
		for(int j=0;j<=20;j++)
		{
		}
	}*/
	return 0;
}

