#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int N=5e5+10,Mod=998244353,inf=1e9+10;
int n,m,T,a[N],b[N],c[N],idx,cnt[N],ans,bl[N];
bool st[N];
vector<PIII> g[N]; 
struct peo
{
	int a,b,c;
}p[N];
bool cmp(peo x,peo y)
{
	return x.a>y.a; 
}
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res*=x,res%=Mod;
		x*=x,x%=Mod,y>>=1;
	}
	return res;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		memset(bl,0,sizeof bl),memset(st,0,sizeof st),memset(cnt,0,sizeof cnt),idx=0,ans=0;
		for(int i=0;i<3;i++) g[i].clear();
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i],p[++idx]={a[i],0,i},p[++idx]={b[i],1,i},p[++idx]={c[i],2,i};
		sort(p+1,p+idx+1,cmp);
		for(int i=1;i<=idx;i++) if(!st[p[i].c]) ans+=p[i].a,st[p[i].c]=1,cnt[p[i].b]++,g[p[i].b].push_back({p[i].a-a[p[i].c],{p[i].c,0}}),g[p[i].b].push_back({p[i].a-b[p[i].c],{p[i].c,1}}),g[p[i].b].push_back({p[i].a-c[p[i].c],{p[i].c,2}}),bl[p[i].c]=p[i].b;
//		cout<<ans<<'\n';
//		for(int i=1;i<=n;i++) cout<<bl[i]<<'\n';
//for(int i=0;i<=2;i++) cout<<cnt[i]<<' ';
//cout<<'\n';
		memset(st,0,sizeof st);
		for(int i=0;i<=2;i++) if(cnt[i]>n/2)
		{
			sort(g[i].begin(),g[i].end());
			for(PIII x:g[i])
			{
				int mn=x.first,ni=x.second.first,id=x.second.second;
//				cout<<i<<' '<<mn<<' '<<id<<' '<<cnt[i]<<'\n';
				if(id!=i&&cnt[id]+1<=n/2&&!st[ni]) st[ni]=1,ans-=mn,cnt[id]++,cnt[i]--,g[id].push_back(x);//,cout<<"?";
				if(cnt[i]<=n/2) break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}