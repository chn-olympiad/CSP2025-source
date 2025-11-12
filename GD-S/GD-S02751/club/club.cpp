#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N=1e5+10;
int a[N][4],b[4],cnt[4],id[N][4],d[N];
void init(int x)
{
	for(int i=1;i<=3;i++)
		b[i]=a[x][i],id[x][i]=i;
	for(int i=1;i<=3;i++)
		for(int j=1;j<3;j++)
			if(b[j]<b[j+1])
			{
				swap(b[j],b[j+1]);
				swap(id[x][j],id[x][j+1]);
			}
	return;
}
void solve()
{
	int ans=0,m=n/2,up=1,t=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++)
	{
		ans+=a[i][id[i][1]];
		cnt[id[i][1]]++;
	}
	if(cnt[2]>cnt[1]) up=2;
	if(cnt[3]>cnt[up]) up=3;
	for(int i=1;i<=n;i++)
		if(id[i][1]==up) d[++t]=a[i][id[i][1]]-a[i][id[i][2]];
	sort(d+1,d+t+1);
	for(int i=1;i<=cnt[up]-m;i++)
		ans-=d[i];
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			init(i);
		}
		solve();
	}
	return 0;
}
