#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio> 
#include <cstring>
using namespace std;
int n,l,clut[5],a[100010][5],clu[100010];
struct tj
{
	int id,tc,js;
};
bool cmp(tj x,tj y)
{
	if (x.js!=y.js)return x.js<y.js;
	return x.id<y.id;
}
vector<tj>b;
void get_to(int mb_clu)
{
	if (clut[mb_clu]<=n/2)return;
	for (int i=0;i<l&&clut[mb_clu]>n/2;i++)
	{
		tj temp=b[i];
		if (clu[temp.id]==mb_clu&&clut[temp.tc]<n/2)
		{
			clut[mb_clu]--;
			clut[temp.tc]++;
			clu[temp.id]=temp.tc;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(clut,0,sizeof(clut));
		memset(clu,0,sizeof(clu));
		b.clear();
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		for (int i=1;i<=n;i++)
		{
			int maxn=-1,maxt;
			for (int j=0;j<3;j++)if (a[i][j]>maxn)maxn=a[i][j],maxt=j;
			clut[maxt]++;
			clu[i]=maxt;
			for (int j=0;j<3;j++)
			{
				tj now={i,j,abs(maxn-a[i][j])};
				if (j!=maxt)b.push_back(now);
			}
		}
		l=b.size();
		sort(b.begin(),b.end(),cmp);
		get_to(0);
		get_to(1);
		get_to(2);
		long long sum=0;
		for (int i=1;i<=n;i++)sum+=a[i][clu[i]];
		printf("%lld\n",sum);
	}
	return 0;
}
