#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k,u,v,w,a;
int egnum;
struct edge{
    short x,y;
    ll val;
    short sign;
};
bool operator<(edge a,edge b){
    return a.val<b.val;
}
int c[15];
int At[1000015];
bool used[15];
vector<edge> edges;
vector<set<int> > connect;
ll mintree(){
    ll ret=0;int cnt=0;
    bool flag=0;
    sort(edges.begin(),edges.end());
    for(edge i:edges){
        flag=0;
        cnt++;
        if(At[i.x]==At[i.y]){
            continue;
        }
        ret+=i.val;
        if(i.sign && !used[i.sign]){
            for(edge& j:edges){
                if(j.sign==i.sign && (j.x!=i.x || j.y!=i.y)){
                    j.val-=c[i.sign];
                }
            }
            used[i.sign]=1;
            sort(edges.begin()+cnt,edges.end());
        }
        int A=At[i.x];
        connect[At[i.y]].insert(connect[At[i.x]].begin(),connect[At[i.x]].end());
        for(int j:connect[At[i.x]]){
            At[j]=At[i.y];
        }
        for(int j=2;j<=n;j++){
            if(At[j]!=At[j-1]){
                flag=1;
                break;
            }
        }
        if(!flag){
            return ret;
        }
        connect[A].clear();
    }
    return ret;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","r",stdout);
    scanf("%d%d%d",&n,&m,&k);
    connect.resize(n+k+5);
    bool flag=(k!=0);
    for(int i=1;i<=n+k+2;i++){
        At[i]=i;
        connect[i].insert(i);
    }
    egnum=m+k*n;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&w);
        edges.push_back(edge({u,v,w,0}));
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&a);
            if(a!=0){
                flag=0;
            }
            edges.push_back({j,m+i,a+c[i],i});
        }
        if(c!=0){
            flag=0;
        }
    }
    if(flag){
        cout<<0;
        return 0;
    }else{
        cout<<mintree();
    }
    return 0;
}
