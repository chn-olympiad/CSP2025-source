#include "bits/stdc++.h"
using namespace std;
const int N=1e6+5;
unsigned long long num_of_edge=0,ans=0;
struct edge{
    int u;
    int v;
    int len;
}kkk[N];
struct city{
    int c;
    int mon_link[N];
}city[15];
int s[N],dothead[N];
priority_queue<int,vector<int>,greater<vector<int> > > m;
void add_edge(int u,int v,int len){
    num_of_edge++;
    kkk[num_of_edge].v=v;
    kkk[num_of_edge].u=u;
    kkk[num_of_edge].len=len;
    dothead[u]=num_of_edge;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    memset(s,INT_MAX,sizeof(s));
    s[1]=0;
    for(int i=1;i<=m;i++){
        int u,v,len;
        scanf("%d%d%d",&u,&v,&len);
        add_edge(u,v,len);
        add_edge(v,u,len);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&city[i].c);
        for(int j=1;j<=m;j++){
            scanf("%d",&city[i].mon_link[j]);
        }
    }
    for(int i=1;i!=0;i=dothead[i]){
        int leng=kkk[ dothead [ i ] ].len;
        m.push(leng);
        ans+=m.top();
        m.clear();
    }
    cout<<ans;
    return 0;
}
