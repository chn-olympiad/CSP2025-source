#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 2e4+7; const int M = 2e6+7;
int n,m,k,a[17][N],fr[17],fa[N],cnt=0,ans=0,Allans,p[17],MmM,NnN;
struct edge { int u,v,w; } e[M];
struct cedge { int u,v,w; } ce[M];
inline bool cmp(edge Fir,edge Sec) { return Fir.w<Sec.w; }
int realcheck=0;
inline int f(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=f(fa[x]);
}
inline int reans()
{
	ans=0; cnt=0;
	sort(e+1,e+m+1,cmp);
	rep(i,1,n) fa[i]=i;
	rep(i,1,m)
	{
		if(f(e[i].u)==f(e[i].v)) continue;
		fa[f(e[i].u)]=f(e[i].v);
		cnt++; ans=ans+e[i].w;
		//cout<<e[i].u<<"-"<<e[i].v<<"-"<<e[i].w<<" ";//ts
		if(cnt==n-1) break;
	}
	//cnt==n-1
	return ans;
}
inline void dfs(int x)
{
	if(realcheck==1) return;
	if(x==k+1)
	{
		rep(i,1,m) e[i].u=ce[i].u,e[i].v=ce[i].v,e[i].w=ce[i].w;
		int jia=0; n=NnN; m=MmM;
		rep(i,1,k)
		    if(p[i]==1)
		    {
				jia+=fr[i]; n++;
				rep(j,1,NnN)
				{
					m++;
					e[m].u=n; e[m].v=j; e[m].w=a[i][j];
				}
			}
		Allans=min(Allans,reans()+jia);
		//cout<<Allans<<endl;//ts
		/*ts
		cout<<endl;cout<<"Choose : ";
		int rean=reans(); cout<<endl;
		cout<<rean<<" "<<jia<<"  "<<rean+jia<<endl;
		cout<<" Allans : "<<Allans<<" ";
		Allans=min(Allans,rean+jia);//baoliu!!!!!
		cout<<Allans<<endl;
		cout<<" n: "<<n<<"  m: "<<m<<endl;
		rep(i,1,k) cout<<p[i]<<" ";
		cout<<endl;
		rep(i,1,k) cout<<fr[i]<<" ";
		cout<<endl;
		ts*/
		realcheck--;
		return;
	}
	p[x]=1; dfs(x+1); p[x]=0; dfs(x+1);
	return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k; MmM=m; NnN=n;
	rep(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
	rep(i,1,k)
	{
		cin>>fr[i];
		rep(j,1,n) cin>>a[i][j];
	}
	if(k==0) { cout<<reans(); return 0; }//20pts
	Allans=reans();
	//cout<<Allans<<endl;//ts
	if(m>=100000) realcheck=5;
	if(m>=500000) realcheck=2;
	rep(i,1,m) ce[i].u=e[i].u,ce[i].v=e[i].v,ce[i].w=e[i].w;
    dfs(1);
	cout<<Allans;
	return 0;
}
