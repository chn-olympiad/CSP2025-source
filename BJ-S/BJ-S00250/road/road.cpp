#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define random 1ll*rand()*rand()+1ll*rand()*rand();
#define ioos ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef __int128 i128;
typedef unsigned __int128 u128;
int fa[1145140];
int n,m,k;
inline int findfa(int x){
    return fa[x]=fa[x]==x?x:findfa(fa[x]);
}
struct node{
    ll u,v,w;
}e[1145140];
inline bool cmp(node a,node b){
    return a.w<b.w;
}
vector<node>edge;
inline ll kruskal(){
    for(int i=1;i<=n;i++)fa[i]=i;
    ll ans=0;
    sort(edge.begin(),edge.end(),cmp);
    for(int i=0;i<edge.size();i++)
        if(findfa(edge[i].u)!=findfa(edge[i].v)){
            ans+=edge[i].w;
            fa[findfa(edge[i].u)]=findfa(edge[i].v);
        }
    return ans;
}
ll d[10][1145140];
bool v[10];
ll ans=0x80000000;
inline void dfs(int cur){
    //printf("cur:%d\n",cur);
    if(cur==k+1){
        edge.clear();
        for(int i=1;i<=m;i++)
            edge.push_back(e[i]);
        int tn=n;
        ll sum=0;
        for(int i=1;i<=k;i++)
            if(v[i]){
                n++;
                for(int j=1;j<=tn;j++)
                    edge.push_back({j,n,d[i][j]});
                sum+=d[i][0];
                //cout<<2<<'\n';
            }
        sum+=kruskal();
        ans=min(ans,sum);
        n=tn;
        return;
    }
    if(d[cur][0]>0){
        v[cur]=false;
        dfs(cur+1);
    }
    v[cur]=true;
    dfs(cur+1);
    return;
}
int main(){
    ioos;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //freopen(
    //freopen(
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=k;i++){
        bool f=true;
        for(int j=0;j<=n;j++)cin>>d[i][j],f=f&(d[i][j]==0);
        if(f){
            cout<<0,exit(0);
        }
    }
    dfs(1);
    cout<<ans;
    return 0;
}
/*
TC DDG
DN VVG
AV XXD
WG DDE

author:uid=533708 from luogu.com.cn
you can find another article in the end of T4 of CSP-J

RCF Experimental School(rdfzcygj.cn) is a con artist
there is no teacher to teach C++
but they said that there will be someone to teach
so if you want to continue your C++ career, please not to come
i hate them
now i'm grade 9 so i can continue my studying in Beijing No.12 high school
but i don't know what to do about my learning on C++ next year
i'm afraid that this might be the last time to join in CSP for me
but actually, these questions are too difficult for me,and T1 took me about 2 hours
this program still can not accept the 3rd big data due to segment error
i tried my best, but still can't reach 175 which is the score line of NOIP last year
what a pity!
i don't want to say goodbye to CSP
but i have to face the fact
(there is 9 minutes left
(there is 8 minutes left
(there is 7 minutes left
(there is 6 minutes left
(there is 5 minutes left
(there is 4 minutes left
(there is 3 minutes left
(there is 2 minutes left
(there is 1 minutes left

---
I'm sorry that there might be several grammar mistakes. if you
find them, please let me know and i will try to improve my
English skills as possible as i can.

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

'kiss the rain':mi so ti ti do do, so ti do ti re re, mi fa so so do do, ti ti-do ti so la, la so mi mi fa fa, mi re re mi mi, la ti ti do re re, mi re do

*/
