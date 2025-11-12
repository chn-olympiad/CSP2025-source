#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,res;
int sum[500005];
struct node{
	int l,r;
}ans[1000005];
bool cmp(node x,node y)
{
	if(x.r!=y.r) return x.r<y.r;
	else return x.l>y.l;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int num=sum[j]^sum[i-1];
			if(num==k)
			{
				ans[++cnt].l=i;
				ans[cnt].r=j;
			}
		}
	}
	sort(ans+1,ans+cnt+1,cmp);
	int maxn=0;
	for(int i=1;i<=cnt;i++)
	{
		if(ans[i].l>maxn)
		{
			maxn=ans[i].r;
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}
