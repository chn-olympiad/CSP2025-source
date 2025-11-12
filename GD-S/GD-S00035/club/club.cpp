#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e4+5;
int T,n;
int sum[5],col[N];
struct node { int b[4]; } a[N];
struct point { int va,vb,id; };
bool operator <(point a,point b) { return max(a.va,a.vb)<max(b.va,b.vb); }
priority_queue<point> p,q,d;
void Solve()
{
	int bt[15]; memset(bt,0,sizeof(bt));
	int num[3]; memset(num,0,sizeof(num));
	LL ans=0,tim=pow(3,n);
	for(int _=1;_<tim;_++)
	{
		for(int j=1;j<=n;j++)
		{
			if(bt[j]==2) bt[j]=0,num[2]--,num[0]++;
			else { num[bt[j]]--,num[++bt[j]]++; break; }
		}
		LL ret=0;
		if(num[0]>n/2||num[1]>n/2||num[2]>n/2) continue;
		for(int j=1;j<=n;j++)
			ret+=a[j].b[bt[j]+1];
		ans=max(ans,ret);
	}
	printf("%lld\n",ans);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].b[1],&a[i].b[2],&a[i].b[3]);
		if(n<=10)
		{
			Solve();
			continue;
		}
		sort(a+1,a+1+n,[](node a,node b){ return a.b[1]>b.b[1]; });
		sum[1]=sum[2]=sum[3]=0;
		while(!p.empty()) p.pop();
		while(!q.empty()) q.pop();
		LL ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=a[i].b[1]; sum[1]++; col[i]=1;
			p.push({a[i].b[2]-a[i].b[1],a[i].b[3]-a[i].b[1],i});
			if(sum[1]>n/2)
			{
				point k=p.top(); p.pop();
				if(k.va>=k.vb)
				{
					sum[1]--; sum[2]++;
					ans+=k.va; col[k.id]=2;
				}
				else
				{
					sum[1]--; sum[3]++;
					ans+=k.vb; col[k.id]=3;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
10
11905 18183 18712
9826 12689 7592
9805 9130 15480
9119 2924 6420
9090 9901 10480
9015 3463 13025
7293 16544 12901
6326 6516 1985
5491 4476 6362
1792 2433 17042    ans: 125440
*/
