#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int ma[10010][10010],c[1010],co[10010][1010];
bool st[10010];
void prim(){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >qu;
    st[1]=true;
    for(int i=1;i<=n;i++){
        if(ma[1][i]!=-1){
            qu.push(make_pair(ma[1][i],i));
        }
    }
    while(qu.size()){
        pair<int,int> a=qu.top();
        qu.pop();
        int x=a.second;
        if(st[x])continue;
        ans+=a.first;
        st[x]=true;
        for(int i=1;i<=n;i++){
            if(ma[x][i]!=-1)qu.push(make_pair(ma[x][i],i));
        }
    }
    return ;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ma[i][j]=-1;
    for(int i=1;i<=m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        ma[u][v]=w;
        ma[v][u]=w;
    }
    bool flag=false;
    if(k!=0) flag=true;
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0)flag=false;
        for(int i=1;i<=n;i++){
                scanf("%d",&co[i][n]);
                if(co[i][n]!=0)flag=false;
        }
    }
    if(flag){
        printf("0\n");
        return 0;
    }
    if(k==0)prim();
    cout<<ans<<endl;
    return 0;
}
