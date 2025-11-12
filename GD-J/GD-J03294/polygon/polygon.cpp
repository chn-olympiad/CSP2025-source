#include<bits/stdc++.h>
using namespace std;
long long tot=0;
int bz[5005],bz1[5005],sum[5005];
int a[5005],b[5005],n;
void dfs(int x,int l,int sum)
{
	if(x>l)
	{
		int maxx=b[1];
		int bbz=0;
		for(int i=2;i<=l;i++)
		{
			maxx=max(maxx,b[i]);
			if(b[i]<=b[i-1])
			bbz=1;
		}
		if(sum>maxx*2&&bbz==0)
		{
			tot++;
			tot=tot%992844353;
		}
		return ;
	}
	for(int i=x;i<=n;i++)
	{
		if(bz[a[i]]<=bz1[a[i]])
		{
			b[x]=a[i];
			bz[a[i]]++;
			dfs(x+1,l,sum+a[i]);
			bz[a[i]]--;
		}
	}
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		bz1[a[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,i,0);
	}
	cout<<tot;
} 
