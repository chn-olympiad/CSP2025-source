//15min，啥玩意怎么 n 是 1e4，被诈骗了
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+5,M=15;
int n,m,k,prt[N],pos[M],tot,now[M],c[M];
vector<array<int,3> >s[M];
int gf(int x){if(x==prt[x])return x;return prt[x]=gf(prt[x]);}
void merge(int x,int y){x=gf(x),y=gf(y);if(x!=y)prt[x]=y;}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	vector<array<int,3> >eg,eg1;
	for(int i=1,x,y,v;i<=m;i++)scanf("%d %d %d",&x,&y,&v),eg.push_back({v,x,y});
	sort(eg.begin(),eg.end());
	for(int i=1;i<=n;i++)prt[i]=i;
	ll ans=0;
	for(auto i:eg)
	{
		if(gf(i[1])==gf(i[2]))continue;
		eg1.push_back(i),merge(i[1],i[2]),ans+=i[0];
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1,x;j<=n;j++)scanf("%d",&x),s[i].push_back({x,n+i+1,j});
	}
	for(int i=0;i<k;i++)sort(s[i].begin(),s[i].end());
	s[k]=eg1;
	for(int i=1;i<(1<<k);i++)
	{
		tot=0;
		ll res=0;
		for(int j=0;j<k;j++)if(i>>j&1)tot++,pos[tot]=j,res+=c[j];
		pos[0]=k;
		vector<array<int,3> >temp;
		for(int j=0;j<=tot;j++)now[j]=0;
		while(1)
		{
			int mn=1e9+1,mnp=0;
			for(int j=0;j<=tot;j++)if(now[j]<s[pos[j]].size() && s[pos[j]][now[j]][0]<mn)mn=s[pos[j]][now[j]][0],mnp=j;
			if(mn<1e9+1)temp.push_back(s[pos[mnp]][now[mnp]]),now[mnp]++;
			else break;
		}
		for(int j=1;j<=n+k;j++)prt[j]=j;
		for(auto j:temp)
		{
			if(gf(j[1])==gf(j[2]))continue;
			merge(j[1],j[2]),res+=j[0];
		}
		ans=min(ans,res);
	}
	printf("%lld\n",ans);
	return 0;
}