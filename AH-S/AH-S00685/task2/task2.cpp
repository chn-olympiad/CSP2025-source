#include<bits/stdc++.h>
using namespace std;
#define gt() getchar()
#define min(a,b) a<b?a:b
typedef long long ll;
const int mn=2*1e6+1;
int n,m,k,f[mn],h[mn],tot,vis[mn],sum,l[11][mn],r[11],dis[10001][10001];
int findx(int x){
    if(f[x]==x) return x;
    return f[x]=findx(f[x]);
}
void merge(int x,int y){
    x=findx(x),y=findx(y);
    if(x!=y) f[x]=f[y];
    return;
}
struct node{
    int nt,v,w;
}e[mn*10];
void add(int a,int b,int c){
    e[++tot].nt=a;
    h[a]=tot;
    e[tot].v=b;
    e[tot].w=c;
}
bool cmp(node a,node b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) {f[i]=i;}
    for(int i=1;i<=m;i++){
        int x,y,z;cin>>x>>y>>z;
        add(x,y,z);dis[x][y]=1;dis[y][x]=1;
    }
    for(int i=1;i<=k;i++){
        cin>>r[i];
        for(int j=1;j<=n;j++){
            cin>>l[i][j];
        }
    }
    for(int i=1;i<=m;i++){
		int w=e[i].w;
		for(int j=1;j<=k;j++){
			w=min(w,r[j]+l[j][e[i].nt]+l[j][e[i].v]);
		}
	    e[i].w=w;	
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			int w=1e9;
			if(dis[i][j]) continue;
			for(int p=1;p<=k;p++){
				w=min(w,r[p]+l[p][i]+l[p][j]);
				}
			add(i,j,w);
			}
		}
    sort(e+1,e+tot+1,cmp);
    tot=0;
    for(int i=1;i<=m;i++){
        if(findx(e[i].nt)!=findx(e[i].v)){
            merge(e[i].nt,e[i].v);
            int w=e[i].w;
            sum+=w;
            tot++;
            if(tot==n-1) break;
        }
    }
    cout<<sum<<endl;
    return 0;
}
