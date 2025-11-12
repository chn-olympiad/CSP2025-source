#include<bits/stdc++.h>
using std::min;
using std::max;
using std::pair;
using std::vector;
#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define edl putchar('\n')
#define lp first
#define rp second
#define lowbit ((x)&(-(x)))
const int inf=0x3f3f3f3f3f3f3f3f;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f*x;
}
void write(int x)
{
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void print(int x,char ed='\n'){write(x);putchar(ed);}
const int N=1e4+100,M=1e6+100,P=1e9+7;
int n,m,k,c[15],a[15][N],fa[N];
pip e[M];
int anc(int u){return fa[u]<0?u:(u=anc(fa[u]));}
void merge(int X,int Y)
{
	X=anc(X),Y=anc(Y);
	if(X==Y) return ;
	if(fa[X]>fa[Y]) std::swap(X,Y);
	fa[X]+=fa[Y];fa[Y]=X;
}
namespace solve1{
	std::priority_queue<pip,std::vector<pip>,std::greater<pip> > pq;
	void run()
	{
		for(int i=1;i<=n;i++) fa[i]=-1;
		for(int i=1;i<=m;i++) pq.push(e[i]);
		for(int i=1;i<=k;i++)
		{
			int eq=0;
			for(int j=1;j<=n;j++) if(a[i][j]==0){eq=j;break;}
			for(int j=1;j<=n;j++)
			{
				if(j==eq) continue;
				pq.push({a[i][j],{j,eq}});
			}
		}
		int ans=0;
		while(pq.size())
		{
			pip cur=pq.top();pq.pop();
			int u=cur.rp.lp,v=cur.rp.rp,w=cur.lp;
			if(anc(u)==anc(v)) continue;
			ans+=w;merge(u,v);
		}
		print(ans);
	}
}
namespace solve2{
	pip ne[1100];
	std::priority_queue<pip,std::vector<pip>,std::greater<pip> > pq;
	void run()
	{
		for(int i=1;i<=n;i++) fa[i]=-1;
		for(int i=1;i<=m;i++) pq.push(e[i]);
		m=0;
		int ans=0;
		while(pq.size())
		{
			pip cur=pq.top();pq.pop();
			int u=cur.rp.lp,v=cur.rp.rp,w=cur.lp;
			if(anc(u)==anc(v)) continue;
			merge(u,v);ne[++m]=cur;ans+=w;
		}
		for(int S=0;S<(1<<k);S++)
		{
			int ret=0;
			for(int i=1;i<=k;i++)
			{
				if(!((S>>(i-1))&1)) continue;ret+=c[i];
				for(int j=1;j<=n;j++) pq.push({a[i][j],{j,n+i}});
			}
			for(int i=1;i<=m;i++) pq.push(ne[i]);
			for(int i=1;i<=n+k;i++) fa[i]=-1;
			while(pq.size())
			{
				pip cur=pq.top();pq.pop();
				int u=cur.rp.lp,v=cur.rp.rp,w=cur.lp;
				if(anc(u)==anc(v)) continue;
				merge(u,v);ret+=w;
			}
			ans=min(ans,ret);
		}
		print(ans);
	}
}
namespace solve3{
	int pt[15];
	pip ne[N];
	std::vector<pii> na[15];
	std::priority_queue<pii,std::vector<pii>,std::greater<pii> > pq1,pq2;
	void run()
	{
		for(int i=1;i<=n;i++) fa[i]=-1;
		for(int i=1;i<=m;i++) pq1.push({e[i].lp,i});
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++) na[i].push_back({a[i][j],j});
			sort(na[i].begin(),na[i].end());
		}
		m=0;
		int ans=0;
		while(pq1.size())
		{
			int cur=pq1.top().rp;pq1.pop();
			int u=e[cur].rp.lp,v=e[cur].rp.rp,w=e[cur].lp;
			if(anc(u)==anc(v)) continue;
			merge(u,v);ne[++m]=e[cur];ans+=w;
		}
		for(int S=0;S<(1<<k);S++)
		{
			int ret=0,cnt=n-1;
			for(int i=1;i<=k;i++)
			{
				if(!((S>>(i-1))&1)) continue;ret+=c[i];pt[i]=0;
				pq2.push({na[i][pt[i]].lp,i});cnt++;
			}
			for(int i=1;i<=m;i++) pq1.push({ne[i].lp,i});
			for(int i=1;i<=n+k;i++) fa[i]=-1;
			while(cnt)
			{
				if(pq1.size()&&(pq2.empty()||pq1.top()<=pq2.top()))
				{
					int cur=pq1.top().rp;pq1.pop();
					int u=ne[cur].rp.lp,v=ne[cur].rp.rp,w=ne[cur].lp;
					if(anc(u)==anc(v)) continue;
					merge(u,v);ret+=w;cnt--;
				}
				else
				{
					int cur=pq2.top().rp;pq2.pop();
					int u=cur+n,v=na[cur][pt[cur]].rp,w=na[cur][pt[cur]].lp;
					pt[cur]++;if(pt[cur]<n) pq2.push({na[cur][pt[cur]].lp,cur});
					if(anc(u)==anc(v)) continue;
					merge(u,v);ret+=w;cnt--;
				}
			}
			while(pq1.size()) pq1.pop();
			while(pq2.size()) pq2.pop();
			ans=min(ans,ret);
		}
		print(ans);
	}
}
//namespace solve4{
//	vector<pip> pq,me[15];
//	int ans=0;
//	void dfs(int i,int cst,vector<pip> &cur)
//	{
//		if(i==k+1) return ;dfs(i+1,cst,cur);
//		for(int j=1;j<=n+k;j++) fa[j]=-1;
//		int ret=cst+c[i];vector<pip> ncur;
//		for(auto it1=cur.begin(),it2=me[i].begin();;)
//		{
//			if(it1==cur.end()&&it2==me[i].end()) break;
//			pip Cur={0,{0,0}};
//			if(it1==cur.end()) Cur=*it2++;
//			else if(it2==me[i].end()) Cur=*it1++;
//			else
//			{
//				if(*it1<=*it2) Cur=*it1++;
//				else Cur=*it2++;
//			}
//			int u=Cur.rp.lp,v=Cur.rp.rp,w=Cur.lp;
//			if(anc(u)==anc(v)) continue;
//			merge(u,v);ans+=w;ncur.push_back(Cur);
//		}
//		ans=min(ans,ret);
//		dfs(i+1,cst+c[i],ncur);
//	}
//	void run()
//	{
//		for(int i=1;i<=k;i++){for(int j=1;j<=n;j++) me[i].push_back({a[i][j],{n+i,j}});sort(me[i].begin(),me[i].end());}
//		for(int i=1;i<=n+k;i++) fa[i]=-1;
//		for(int i=1;i<=m;i++) pq.push_back(e[i]);
//		sort(pq.begin(),pq.end());
//		vector<pip> st;
//		for(auto cur:pq)
//		{
//			int u=cur.rp.lp,v=cur.rp.rp,w=cur.lp;
//			if(anc(u)==anc(v)) continue;
//			merge(u,v);ans+=w;st.push_back(cur);
//		}/*print(1);*/print(ans);
//		dfs(1,0,st);
//		print(ans);
//	}
//}
signed main()
{
//	system("fc road.out road1.ans");
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[i]={w,{u,v}};
	}
	int flgA=1;
	for(int i=1;i<=k;i++)
	{
		int flgi=0;c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read(),flgi|=(a[i][j]==0);
		flgi&=(c[i]==0);flgA&=flgi; 
	}
	if(flgA) solve1::run();
	else if(n<=1000) solve2::run();
	else solve3::run();
	
	return 0;
}
//15:33 64pts
//passed all examples
