#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
using namespace std;

const int N=1e6+5;

int a[N];
long long pfx[N];
struct node
{
	int l,r;
};
node b[N];
bool cmp(node a,node b)
{
	if(a.r!=b.r)
	{
		return a.r<b.r;
	}
	return a.l<b.l;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	//cout<<(1^0^3)<<" "<<(1^3^0)<<" "<<(3^0^1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pfx[i]=a[i]^pfx[i-1];
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			//printf("[%d,%d]=%d\n",j,i,pfx[i]-pfx[j-1]);//
			if(abs(pfx[i]-pfx[j-1])==k)
			{
				ans++;
				b[ans].l=j;
				b[ans].r=i;
			}
		}
	}
	sort(b+1,b+ans+1,cmp);
	int nowl=-1,nowr=2e9,maxn=0;
	for(int i=1;i<=ans;i++)
	{
		/*if(b[i].r!=b[i-1].r)
		{
			nowr=2e9;
			nowl=b[i-1].r;
		}*/
		if(b[i].l>nowl)
		{
			if(b[i].r<=nowr)
			{
				nowl=b[i].r;
				//nowr=b[i].r;
				//cout<<b[i].l<<":"<<b[i].r<<endl;//
				maxn++;
			}
			//nowl=b[i].l;
		}
	}
	cout<<maxn;
	
	return 0;
}
