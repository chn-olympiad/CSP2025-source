#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node2{
    int u,v,w;
}c[N];
int n,m,k,a[20][N],vis[N];
bool cmp(node2 s1,node2 s2){
    return s1.w<s2.w;
}
int find_(int x){
    if(vis[x]==x)return x;
    return vis[x]=find_(x);
}
int kus(){
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        vis[i]=i;
    }
    sort(c+1,c+m+1,cmp);
    for(int i=1;i<=m;i++){
        int x=find_(c[i].u),y=find_(c[i].v);
        if(x==y)continue;
        vis[y]=x;
        ans+=c[i].w;
        cnt++;
        if(cnt==n-1)return ans;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>c[i].u>>c[i].v>>c[i].w;
    }
    for(int i=1;i<=k;i++){
            int x;cin>>x;
        for(int j=1;j<=n;j++){
            cin>>x;a[i][j]=x;
        }
    }
    for(int l=1;l<=k;l++){
        for(int i=1;i<=n;i++){
            for(int j=1+i;j<=n;j++){
                c[++m].u=i;
                c[m].v=j;
                c[m].w=a[l][i]+a[l][j];
            }
        }
    }
    cout<<kus();
    return 0;
    fclose(stdin);
    fclose(stdout);
}

