//my solution is totally CH4.
//i will get 16pts
#include<bits/stdc++.h>
using namespace std;
struct node{
    int u;int v;int w;
};
vector<node> m[10100];
int mp[15][10100],tag[10100],ans;
int N,M,n[10100],K;
node side[1001000];int cnt ;
bool cmp(node a,node b){
    return a.w<b.w;
}


int  main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>N>>M>>K;
    int minw,stu,stv;
    for(int i=1;i<=M;i++){
        int u,v,w;
        cin>>u>>v>>w;
        node a;
        a.u=u;a.v=v;a.w=w;
        m[u].push_back(a);m[v].push_back(a);
        if(w<minw){
            minw=w;stu=u;stv=v;
        }

    }
    for(int i=1;i<=K;i++){
        for(int j=0;j<=N;j++){
            cin>>mp[i][j];
        }
    }
    ans+=minw;

    tag[stu]=1;tag[stv]=1;
    for(int i=0;i<m[stu].size();i++){
        if(tag[m[stu][i].v]==0||tag[m[stu][i].u]==0)
        side[++cnt]=m[stu][i];
    }
    for(int i=0;i<m[stv].size();i++){
        if(tag[m[stv][i].v]==0||tag[m[stv][i].u]==0)
        side[++cnt]=m[stv][i];
    }
    for(int i=2;i<=N;i++){
        sort(side+1,side+cnt,cmp);
        int se=0;
        while(tag[side[se].v]==1&&tag[side[se].u]==1)se++;
        if(tag[side[se].v]==1)stv=side[se].u;else stv=side[se].v;
        tag[side[se].v]=1;tag[side[se].u]=1;
        for(int i=0;i<m[stv].size();i++){
            if(tag[m[stv][i].v]==0||tag[m[stv][i].u]==0)
            side[++cnt]=m[stv][i];
        }
        ans+=side[se].w;
    }

    cout<<ans;
    return 0;
}
