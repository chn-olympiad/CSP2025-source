#include<bits/stdc++.h>
using namespace std;
int par[1000010],n,m,k,k_list[15][1000010],ind=0,jiazhi,lufei;
long long ans=0;
int findd(int n){
    if(par[n]==n)return n;
    return par[n]=findd(par[n]);
}
void join(int a,int b){
    int aa=findd(a),bb=findd(b);
    par[aa]=bb;
}
struct Edge{
    int sum,u,v;
};
Edge edge[1000010];
bool cmp(Edge a,Edge b){
    return a.sum<b.sum;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)par[i]=i;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[i].sum=c;
        edge[i].u=a;
        edge[i].v=b;
    }
    ind=m;
    for(int i=1;i<=k;i++){
        cin>>jiazhi;
        for(int j=1;j<=n;j++)cin>>k_list[i][j];
        if(jiazhi==0){
            for(int x=1;x<n;x++){
                for(int y=x+1;y<=n;y++){
                    edge[++ind].sum=k_list[i][x]+k_list[i][y];
                    edge[ind].u=x;
                    edge[ind].v=y;
                }
            }
        }
    }
    sort(edge+1,edge+1+ind,cmp);
    for(int i=1;i<=n;i++){
        int fu=findd(edge[i].u),fv=findd(edge[i].v);
        if(fu!=fv){
            par[fu]=fv;
            ans+=edge[i].sum;
        }
    }
    cout<<ans;
    return 0;
}
/*
1 2 2
1 4 9
2 3 5
2 4 1
3 4 3
4 5 8
*/
