#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=1e4+5;
struct ro{
    int u,v,w;
}s[N];
int n,m,k,a[15][M],c[M],book[N];
long long ans;
void dfs(int x){
    book[x]=1;
    for(int i=1;i<=m;i++){
        if(book[s[i].v]==0){
            ans+=s[i].w;
            book[s[i].v]=1;
            dfs(s[i].v);
        }
    }
    cout<<ans;
    exit(0);
}
bool cmp(ro a,ro b){
    return a.w<b.w;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>s[i].u>>s[i].v>>s[i].w;

    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    if(c[1]==0){
        for(int j=1;j<=n;j++){
            ans+=a[1][j];
        }
        cout<<ans;
        return 0;
    }else if(k==0){
        sort(s+1,s+1+m,cmp);
        dfs(1);
    }else{
        for(int j=1;j<=m;j++){
            ans+=s[j].w;
        }
        cout<<ans;
    }
    return 0;
}
