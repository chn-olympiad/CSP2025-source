//GZ-S00304 观山湖中学 熊浩 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e6+20,N=1e4+20;
struct node{
	int u,v;
	ll w,c;
	int f;//f:乡村标记 第i个乡村 
}tr[M+13*N];
//乡村开始时要加上创建代价,使用后use_i变为true,就不用再加创建代价了 
bool cmp(node a,node b){ return a.w<b.w; }
int fa[N];//最小生成树 
ll n,m,k,tc[15],tb,idx,need,ans,cnt;//tc-创建代价 
bool use[15];//记录这个乡村是否被用过 
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>tr[i].u>>tr[i].v>>tr[i].w;
	idx+=m;
	for(int i=1;i<=k;i++){
		cin>>tc[i];
		for(int j=1;j<=n;j++){  //映射位置 m+i*n+j 
			cin>>tb,tr[++idx].u=n+i,tr[idx].v=j,tr[idx].w=tb+tc[i];
//			if(tg>tb) idx=m+i*n+j ,tg=tb;
			tr[idx].f=i;
		}
	}
	for(int i=1;i<=n+k;i++) fa[i]=i;
	sort(tr+1,tr+m+idx+1,cmp);
	need=n-1;
	for(int i=1;i<=m+k*n;i++){
		int fu=find(tr[i].u),fv=find(tr[i].v);
		if(fu!=fv){
			if(tr[i].f&&!use[tr[i].f]){
				ans+=tr[i].w,use[tr[i].f]=true,cnt++,need++;
				fa[fu]=fv;
				cout<<tr[i].u<<' '<<tr[i].v<<' '<<1<<'\n';
				continue;
			}
			else if(tr[i].f&&use[tr[i].f]){
				ans+=tr[i].w-tc[tr[i].f],cnt++;
				if(cnt==need){cout<<ans; return 0; }
				fa[fu]=fv;
				cout<<tr[i].u<<' '<<tr[i].v<<' '<<2<<'\n';
				continue;
			}
			else if(!tr[i].f){
				ans+=tr[i].w,cnt++;
				if(cnt==need){cout<<ans; return 0; }
				fa[fu]=fv;
				cout<<tr[i].u<<' '<<tr[i].v<<' '<<3<<'\n';
				continue;
			}
		}
//		cout<<tr[i].u<<' '<<tr[i].v<<' '<<tr[i].w<<' '<<tr[i].f<<'\n';
	}
	return 0;
}
