#include<bits/stdc++.h>
using namespace std;
struct data
{
	int l,r;
} d[500005];
int sum[500005],n,k,a[500005],ans,f=1;
bool cmp(data x,data y)
{
	return x.l<y.l;
}
int dfs(int c,int t)
{
	int maxx=t;
	int b;
	for(int i=1;i<=f;i++)
	{
		if(d[i].l==c)
		{
			b=dfs(d[i].r+1,t+1);
			if(b>maxx) maxx=b;
		}
	}
	return maxx;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]|a[i];
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(sum[j]|sum[i]==k)
			{
				cout<<(sum[j]|sum[i]);
				d[f].l=i;
				d[f].r=j;
				f++;
			}
		}
	}
	f--;
	sort(d+1,d+n+1,cmp);
	for(int i=1;i<=f;i++) cout<<d[i].l<<" "<<d[i].r<<endl; 
	cout<<dfs(1,0);
	return 0;
}
// i want slepp
