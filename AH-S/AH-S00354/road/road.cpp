#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,a[12][10005],c[12],n2,fa[10015];
ll ans;
bool b[12];
struct node{
    int x,y,w;
}e[1000005],e2[1000005],e3[10005];
void read(int &x){
    x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-48;
        ch=getchar();
    }
}
int find(int x){
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
bool cmp(node x,node y){
    return x.w<y.w;
}
ll kru(){
    sort(e2+1,e2+n2+1,cmp);
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
    ll cnt=0;
    for(int i=1;i<=n2;i++){
        int fx=find(e2[i].x),fy=find(e2[i].y);
        if(fx!=fy){
            cnt+=e2[i].w;
            fa[fy]=fx;
        }
    }
    return cnt;
}
void dfs(int x,ll cnt){
    if(cnt>=ans) return;
    if(x>k){
        for(int i=1;i<n;i++){
            e2[i]=e3[i];
        }
        n2=n-1;
        int n22=n;
        for(int i=1;i<=k;i++){
            if(b[i]){
                n22++;
                for(int j=1;j<=n;j++){
                    e2[++n2].x=j;
                    e2[n2].y=n22;
                    e2[n2].w=a[i][j];
                }
            }
        }
        ans=min(ans,cnt+kru());
        return;
    }
    b[x]=1;
    dfs(x+1,cnt+c[x]);
    b[x]=0;
    dfs(x+1,cnt);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for(int i=1;i<=m;i++){
        read(e[i].x),read(e[i].y),read(e[i].w);
    }
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    for(int i=1;i<=m;i++){
        int fx=find(e[i].x),fy=find(e[i].y);
        if(fx!=fy){
            ans+=e[i].w;
            e3[++n2]=e[i];
            fa[fy]=fx;
        }
    }
    for(int i=1;i<=k;i++){
        read(c[i]);
        for(int j=1;j<=n;j++){
            read(a[i][j]);
        }
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
5
x y z
a b c

x

n/2
*/
