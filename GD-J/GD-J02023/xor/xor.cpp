#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const int N=3e6+10;
const int inf=0x3f3f3f3f;
ll n,k;
ll a[N],sum[N];
int vis[N],flag[N];
int flag1,flag2,ans,len;
struct node
{
	int l,r,lo,er;
}num[N];
bool cmp(node xx,node yy)
{
	if(xx.er!=yy.er)
		return xx.er<yy.er;
	else 
		return xx.lo<yy.lo;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=1)flag1=1;
		if(a[i]!=1 and a[i]!=0)flag2=1;
	}
	if(!flag1)
	{
		printf("%d",n/2);
		return 0;
	}
	if(!flag2)
	{
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					ans++;
				}
				else if(a[i]==a[i+1])
				{
					ans++;
					i++;
				}
			}
			printf("%d",ans); 
			return 0;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(a[i])ans++;
			}
			printf("%d",ans);
			return 0;
		} 
	}
	
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			int x=sum[i]^sum[j-1];
			if(x==k)//j^...^i==k
			{
				vis[i]=j;
				break;
			} 
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		{
			len++;
			num[len].l=vis[i];
			num[len].r=i;
			num[len].lo=i-vis[i]+1;
		}
	}
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=len;j++)
		{
			if(i==j)continue;
			int l=num[i].l,r=num[i].r;
			int x=num[j].l,y=num[j].r;
			if((l<=x and x<=r) or (l<=y and y<=r) or (x<=l and l<=y) or (x<=r and r<=y))
			{
				num[i].er++;
			}
		}
	}
	sort(num+1,num+len+1,cmp);
	for(int i=1;i<=len;i++)
	{
		int k=0;
		for(int j=num[i].l;j<=num[i].r;j++)
		{
			if(flag[j])
			{
				k=1;
				break;
			}
		}
		if(!k)
		{
			ans++;
			for(int j=num[i].l;j<=num[i].r;j++)
			{
				flag[j]++;
			}
			
		}
	}
	printf("%d",ans);
	 return 0;
}
