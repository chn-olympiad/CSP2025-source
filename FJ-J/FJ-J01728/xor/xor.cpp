#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+10;
const int M=1e4+10;
struct node
{
	int l,r;
}qj[N];
int n,k,cnt,last,ans,a[N],xo[N];
int qjxo(int la,int ri)
{
	return xo[ri]^xo[la-1];
}
bool cmp(node a,node b)
{
	if(a.r==b.r)
	{
		return a.l>b.l;
	}
	return a.r<b.r;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(i==1) xo[1]=a[i];
		else xo[i]=xo[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(qjxo(i,j)==k)
			{
				qj[++cnt].l=i,qj[cnt].r=j;
			}
		}
	}
	sort(qj+1,qj+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		if(qj[i].l>last)
		{
			last=qj[i].r;
			ans++;
		}
	} 
	printf("%d",ans);
	return 0;
}
