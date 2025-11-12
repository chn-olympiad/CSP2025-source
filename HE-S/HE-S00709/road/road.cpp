#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
struct edge{
	int u,v,w;
}e[M];
int n,m,k;
int c[K],a[K][N],fa[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int fd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fd(fa[x]);
}
void mg(int x,int y){
	x=fd(x),y=fd(y);
	fa[x]=y;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++) {
    	cin>>e[i].u>>e[i].v>>e[i].w;
    }
    for(int i=1;i<=k;i++){
    	cin>>c[i];
    	for(int j=1;j<=n;j++) {
    		cin>>a[i][j];
		}
	}
	sort(e+1,e+m+1,cmp);
	if(k==0){
		int la=n,sum=0;
		for(int i=1;i<=m;i++){
			if(fd(e[i].u)!=fd(e[i].v)) {
				la--;
				sum+=e[i].w;
				mg(e[i].u,e[i].v);
			}
			if(la==1) break;
		}
		cout<<sum;
	}
	return 0;
}

