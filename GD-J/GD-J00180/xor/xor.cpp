#include<bits/stdc++.h>
using namespace std;
long long int a[101012];
long long int vis[101010];
long long int num[1001011];
long long int id[101010];
struct node
{
	long long int l,r;
}x[1001011];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(vis,0,sizeof(vis));
	long long int n,k,tot=0;
	cin>>n>>k;
	for(long long int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	long long int ans=0;
	long long int l=1,r=0;
	while(l<=n-1)
	{
		ans=(ans xor a[++r]);
		if(r==n+1)
		{
			l++;
			ans=a[l];
			r=l; 
		}
		if(ans==k)
		{
			x[++tot].l=l;
			x[tot].r=r;
		}
	}
	for(long long int i=1;i<=tot;i++)
	{
		num[i]=x[i].r-x[i].l+1;
		id[i]=i;
	}
	for(long long int i=1;i<=tot-1;i++)
	{
		for(long long int j=1;j<=tot-1;j++)
		{
			long long int dl=x[id[j]].l,dr=x[id[j]].r,dll=x[id[j+1]].l,drr=x[id[j+1]].r;
			if((dll>dl and dl>drr) or (dl>dll and dll>dr))
			{
				if(num[j]>num[j+1])
				{
					num[j]=0;
					id[j]=0;
				}
				else
				{
					num[j+1]=0;
					id[j+1]=0;
				}
			}
			else
			{
				if(num[j]>num[j+1])
				{
					swap(num[j],num[j+1]);
					swap(id[j],id[j+1]);
				}
			}
		} 
	}
	long long int sum=0;
	for(long long int i=1;i<=tot;i++)
	{
		for(long long int j=x[id[i]].l;j<=x[id[i]].r and id[i]!=0;j++)
		{
			if(vis[j]==true)
			{
				goto Go;
			}
			else
			{
				vis[j]=true;
			}
		}
		sum++;
		Go:;
	}
	cout<<sum;
}
