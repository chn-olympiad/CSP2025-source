#include<bits/stdc++.h>
using namespace std;
int sum[500010];
int a[500010];

struct node
{
	int flag;
	int l,r;
	bool operator<(node x)const
	{
		return x.r-x.l<this->r-this->l;
	}
}ans[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	int now=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)if(abs(sum[j]-sum[i-1])==k)
		{
			ans[i]={i,j,0};
			now++;
		}
	}
	sort(ans+1,ans+1+now);
	int cnt=0;
	for(int i=1;i<=now;i++)
	{
		if(ans[i].flag==1)continue;
		cnt++;
		for(int j=i+1;j<=now;j++)
		{
			if(ans[j].l<=ans[i].l&&ans[j].r>=ans[i].l||ans[j].l<=ans[i].r&&ans[j].r>=ans[i].r)
			{
				ans[j].flag=1;
			}
		}
	}
	printf("%d",cnt);
	return 0;
}
/*
¿¼ÂÇÇ°×ººÍ 
*/
