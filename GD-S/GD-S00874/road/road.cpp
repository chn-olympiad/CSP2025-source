#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
struct node{
	int u,v,w;
}ed[30000005];
int n,m,k;
int c[15];
int a[15][N];
int cnt=0;
bool cmp(node a,node b){
	return a.w<b.w;
}
int fa[N];
int find(int p){
	if(p!=fa[p]){
		return fa[p]=find(fa[p]);
	}
	return p;
}
void merge(int p1,int p2){
	int r1=find(p1);
	int r2=find(p2);
	if(r1!=r2){
		fa[r1]=fa[r2];
	}
	return;
}
void init(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	return;
}
int kskal(){
	init();
	sort(ed+1,ed+cnt+1,cmp);
	int ans=0;
	for(int i=1;i<=cnt;i++){
		int u=ed[i].u;
		int v=ed[i].v;
		int w=ed[i].w;
		int ru,rv;
		ru=find(u);
		rv=find(v);
		if(find(u)!=find(v)){
			ans+=w;
			merge(u,v);
		}
	}
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        ed[++cnt].u=u;
        ed[cnt].v=v;
        ed[cnt].w=w;
        ed[++cnt].u=v;
        ed[cnt].v=u;
        ed[cnt].w=w;
    }
    bool b=true;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            if(c[i]!=0){
                b=false;
            }
            cin>>a[i][j];
        }
    }
    if(b){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                for(int k=1;k<=n;k++){
                    if(k==j){
                        continue;
                    }
                    ed[++cnt].u=j;
                    ed[cnt].v=k;
                    ed[cnt].w=a[i][j]+a[i][k];
                }
            }
        }
	}
	cout<<kskal();
    return 0;
}

