#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10006],u,v,w,c,a,cnt,ans;
array<long long, 3 > q[1000006];
bool fnd(long long nw,long long tgt){
    if(fa[fa[nw]]!=fa[nw]){fa[nw]=fa[fa[nw]];}
    if(fa[fa[tgt]]!=fa[tgt]){fa[tgt]=fa[fa[tgt]];}
    return fa[nw]==fa[tgt];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        cnt++;
        q[cnt]={w,u,v};

    }
    sort(q+1,q+m+1);
    for(int i=1;i<=k;i++){
        cin>>c;
        for(int j=1;j<=n;j++){
            cin>>a;
            q[cnt]={a,i,j};
        }
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        if(fnd(fa[q[i][1]],fa[q[i][2]]))continue;
        ans+=q[i][0];
        if(fa[q[i][2]]==q[i][2])fa[q[i][2]]=fa[q[i][1]];
        else fa[q[i][1]]=fa[q[i][2]];

    }
    cout<<ans;
    return 0;
}
