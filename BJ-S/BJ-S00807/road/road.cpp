#include<bits/stdc++.h>
#include<vector>
#define int long long
const int maxn=1e4+10;
using namespace std;
int n,m,k,c,sum,ans=INT_MAX,fa[maxn];
struct node{
    int u,v,w;
};
vector<node>e,e1;

int get(int x){
    if(fa[x]==x)return x;
    return fa[x]=get(fa[x]);
}

bool cmp(node a,node b){
    return a.w<b.w;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int x,y,z;
        node tmp;
        fa[i]=i;
        cin>>x>>y>>z;
        tmp.u=x,tmp.v=y,tmp.w=z;
        e.push_back(tmp);
    }
    fa[n+1]=n+1;
    for(auto ee:e){
        int x=get(ee.u),y=get(ee.v);
        if(x!=y){
            fa[x]=y;
            sum+=ee.w;
        }
    }
    ans=min(sum,ans);
    for(int i=1;i<=k;i++){
        e1=e,sum=0;
        for(int i=1;i<=n+1;i++)
            fa[i]=i;
        cin>>c;
        for(int j=1;j<=n;j++){
            node tmp;
            cin>>tmp.w;
            tmp.u=j,tmp.v=n+1;
            e1.push_back(tmp);
        }
        sort(e1.begin(),e1.end(),cmp);
        sum=c;
        for(auto ee:e1){
            int x=get(ee.u),y=get(ee.v);
            if(x!=y){
                fa[x]=y;
                sum+=ee.w;
            }
        }
        ans=min(sum,ans);
    }
    cout<<ans;
}
