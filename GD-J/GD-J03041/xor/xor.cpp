#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=5e5+10,M=(1<<20)+10;
int a[N],sum[N],f[N];
vector <int> s[M];
struct Node
{
	int l,r;
}b[N];
bool cmp(Node x,Node y)
{
	return x.r!=y.r?x.r<y.r:x.l<y.l;
}
int fnd(int x,int y)
{
	int l=0,r=s[x].size()-1,res=-1;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(s[x][mid]>y)
		{
			res=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return res;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		s[sum[i]].push_back(i);
	}
	s[0].push_back(0);
	for(int i=0;i<=n;i++)
	{
		int t=fnd(sum[i]^k,i);
		if(t!=-1) b[++cnt]={i+1,s[sum[i]^k][t]};
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		for(int j=b[i-1].r+1;j<=b[i].r;j++)
			f[j]=f[j-1];
		f[b[i].r]=max(f[b[i].r],f[b[i].l-1]+1);
	}
	printf("%d",f[n]);
	return 0;
}
