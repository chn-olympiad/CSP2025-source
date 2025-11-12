#include<bits/stdc++.h>
using namespace std;
#define int long long
struct st{
    int u,v,w;
    bool operator<(const st& other) const{
        return w<other.w;
    }
};
vector<st> v1;
vector<st> v2[15];
int c[15];
int now,cnt,minn=LLONG_MAX;
int f[100005];
int find(int x){
    if(x!=f[x]) f[x]=find(f[x]);
    return f[x];
}
bool unionn(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y){
        f[x]=y;
        return 1;
    }
    return 0;
}
void fun(int n){
    vector<st> tmp=v1;
    sort(tmp.begin(),tmp.end());
    for(int i=1;i<=n;i++) f[i]=i;
    int ans=now;
    for(st i:tmp){
        bool f=unionn(i.u,i.v);
        if(f) ans+=i.w;
    }
    minn=min(minn,ans);
}
bool flag=1;
int n,m,k;
void dfs(int x){
    if(x>k){
        fun(cnt);
        return ;
    }
    if(!flag) dfs(x+1);
    now+=c[x];
    cnt++;
    for(st i:v2[x]){
        i.u=cnt;
        v1.push_back(i);
    }
    dfs(x+1);
    now-=c[x];
    cnt--;
    for(st i:v2[x]) v1.pop_back();
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        v1.push_back({u,v,w});
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]) flag=0;
        bool exist=0;
        for(int j=1;j<=n;j++){
            int w;
            cin>>w;
            v2[i].push_back({i,j,w});
            if(!w) exist=1;
        }
        if(!exist) flag=0;
    }
    cnt=n;
    dfs(1);
    cout<<minn;
    return 0;
}