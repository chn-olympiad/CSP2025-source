#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    char ch=getchar();
    int x=0;
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x;
}
struct node{
    int u,v,w;
}a[1000005],b[1000005];
bool use[1000005],box[20];
bool cmp(node A,node B){
    return A.w<B.w;
}
int r[20005],k,n,ans=1e18,c[20],rd[20][10005];
int find(int x){
    if(r[x]==x) return x;
    return r[x]=find(r[x]);
}
void merge(int x,int y){
    r[find(x)]=find(y);
}
void dfs(int cur){
    if(cur>k){
        int sum=0,lu=n-1;
        for(int i=1;i<n;i++){
            b[i]=a[i];
        }
        for(int i=1;i<=k;i++){
            if(box[i]){
                sum+=c[i];
                for(int j=1;j<=n;j++){
                    b[++lu]=node{n+i,j,rd[i][j]};
                }
            }
        }
        for(int i=1;i<=n+k;i++) r[i]=i;
        sort(b+1,b+lu+1,cmp);
        for(int i=1;i<=lu;i++){
            if(find(b[i].u)!=find(b[i].v)){
                merge(b[i].u,b[i].v);
                sum+=b[i].w;
            }
        }
        ans=min(ans,sum);
        return ;
    }
    box[cur]=1;
    dfs(cur+1);
    box[cur]=0;
    dfs(cur+1);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    n=read(),m=read(),k=read();
    for(int i=1;i<=m;i++){
        a[i].u=read(),a[i].v=read(),a[i].w=read();
    }
    for(int i=1;i<=k;i++){
        c[i]=read();
        for(int j=1;j<=n;j++){
            rd[i][j]=read();
        }
    }
    sort(a+1,a+m+1,cmp);
    for(int i=1;i<=n;i++) r[i]=i;
    for(int i=1;i<=m;i++){
        if(find(a[i].u)!=find(a[i].v)){
            merge(a[i].u,a[i].v);
            use[i]=1;
        }
    }
    int id=0;
    for(int i=1;i<=m;i++){
        if(use[i]) a[++id]=a[i];
    }
    dfs(1);
    cout<<ans;
    return 0;
}
