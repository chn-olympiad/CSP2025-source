#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e6+2e5;
const int INF=1e18;
inline int read(){
	char ch=getchar();int x=0;bool f=false;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=true;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f) x=-x;
	return x;
}
int n,m,k,nn,mm;
int c[N],a[12][N];
int fa[N];
bool vis[N];
struct node{
	int fr,to,val;
}e[M],rec[M];
bool cmp(node aa,node bb){
	return aa.val<bb.val;
}
int find(int xx){
	if(fa[xx]==xx) return xx;
	else return fa[xx]=find(fa[xx]);
}
int kruskal(){
	for(int i=1;i<=n;i++) fa[i]=i;
	int ans=0;
	sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++){
		int fx=find(e[i].fr),fy=find(e[i].to);
		//cout<<fx<<" "<<fy<<"\n";
		if(fx!=fy){
			fa[fx]=fy;
			ans+=e[i].val;
			//cout<<fx<<" "<<fy<<" "<<e[i].val<<"\n";
		}
	}
	return ans;
}
void solve(){
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			m++;
			e[m].fr=n+i,e[m].to=j,e[m].val=a[i][j];
		}
	}
	n+=k;
	cout<<kruskal();
}

void rev(){
    n=nn,m=mm;
    for(int i=1;i<=m;i++){
        e[i].fr=rec[i].fr,e[i].to=rec[i].to,e[i].val=rec[i].val;
    }
    return;
}

int check(){
    rev();
	int ct=0;
	for(int i=1;i<=k;i++){
        if(!vis[i]) continue;
		ct+=c[i];
		for(int j=1;j<=n;j++){
			m++;
			e[m].fr=n+i,e[m].to=j,e[m].val=a[i][j];
		}
	}
	for(int i=1;i<=k;i++) if(vis[i]) n++;
	return kruskal()+ct;
}

int dfs(int x){
    if(x>n) return check();
    int ans=INF;
    vis[x]=true;
    ans=min(ans,dfs(x+1));
    vis[x]=false;
    ans=min(ans,dfs(x+1));
    return ans;
}

void init(){
	n=read(),m=read(),k=read();
	nn=n,mm=m;
	for(int i=1;i<=m;i++){
		e[i].fr=read(),e[i].to=read(),e[i].val=read();
		rec[i].fr=e[i].fr,rec[i].to=e[i].to,rec[i].val=e[i].val;
	}
	bool flag=true;
	for(int i=1;i<=k;i++){
		c[i]=read();
		if(c[i]>0) flag=false;
		bool flg=false;
		for(int j=1;j<=n;j++){
			a[i][j]=read();
			if(!a[i][j]) flg=true;
		}
		flag=(flag&flg);
	}
	if(flag) solve();
	else cout<<dfs(1);
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
