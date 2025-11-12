#include<bits/stdc++.h>
/*
g++ -O2 -std=c++14 -static -o road road.cpp
*/
using namespace std;
#define int long long
const int N=2e6+16;
int b[15],fa[N];
struct Edge{
    int u,v,w;
}a[N][15];
bool cmp(Edge x,Edge y){
    return x.w<y.w;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    x=find(x),y=find(y);
    fa[x]=y;
}
signed main()
{
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>a[0][i].u>>a[0][i].v>>a[0][i].w;
        for(int j=1;j<=k;j++)a[j][i]=a[0][i];
    }
    for(int i=1;i<=k;i++){
        cin>>b[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][m+j].w;
            a[i][m+j].u=n+1;
            a[i][m+j].v=j;
        }
    }
    int res=0;
    sort(a[0]+1,a[0]+1+m,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1,p=1;p<n;i++){
        if(find(a[0][i].u)!=find(a[0][i].v)){
            res+=a[0][i].w,p++;
            merge(a[0][i].u,a[0][i].v);
        }
    }
    int ans=res;
    for(int j=1;j<=k;j++){
        res=b[j];
        sort(a[j]+1,a[j]+1+m+n,cmp);
        for(int i=1;i<=n+1;i++)fa[i]=i;
        for(int i=1,p=1;p<=n;i++){
            if(find(a[j][i].u)!=find(a[j][i].v)){
                res+=a[j][i].w,p++;
                merge(a[j][i].u,a[j][i].v);
                // cout<<res<<" "<<a[0][i].w<<" "<<i<<endl;
            }
        }
        ans=min(ans,res);
        // cout<<res<<endl;
        // for(int i=1;i<=m+n;i++)cout<<a[j][i].w<<" ";
        // cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}