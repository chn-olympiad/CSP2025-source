#include<bits/stdc++.h>
using namespace std;
const int N=3e6+5;
int n,m,k;
struct op{
    int x,y,w;
}a[N];
int c[15];
int d[15][10005];
int fa[10005];
long long ans=1e13;
op p[N];
bool cmp(op X,op Y){
    return X.w<Y.w;
}
int ft(int x){
    if(fa[x]==x)return x;
    return fa[x]=ft(fa[x]);
}
long long run(int z,int s){
    long long r=0;
    for(int i=1;i<=z-1;i++)p[i]=a[i];
    for(int i=1;i<=s;i++)fa[i]=i;
    sort(p+1,p+z,cmp);
    int v=0;
    for(int i=1;i<=z-1;i++){
        int g=p[i].x,h=p[i].y;
        int j=ft(g),k=ft(h);
        if(j!=k){
			v++;
            fa[j]=k;
            r+=p[i].w;
        }
        if(r>=ans)return ans;
		if(v==s-1)break;
	}
	return r;
}
void dfs(int t,int z,long long f,int s){
	if(f>=ans)return;
    if(t==k+1){
        ans=min(ans,run(z,s)+f);
        return;
    }
    dfs(t+1,z,f,s);
    int cnt=0;
    for(int i=z;i<=z+n-1;i++){
        cnt++;
        a[i].x=n+t;
        a[i].y=cnt;
        a[i].w=d[t][cnt];
    }
    dfs(t+1,z+n,f+c[t],s+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].w);
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)scanf("%d",&d[i][j]);
    }
    dfs(1,m+1,0,n);
    printf("%lld",ans);
    return 0;
}
