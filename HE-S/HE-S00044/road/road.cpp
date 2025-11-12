#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans=0x3f3f3f3f,ok,x[1000];
struct ST{
    int to,num;
};
struct S{
    int now,money,cnt;
};
vector<ST> a[10100];
queue<S> q;
bool cmp(ST a1,ST a2){
    return a1.num<a2.num;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end(),cmp);
    }
    if(k==0){
        q.push({1,0,0});
        while(!q.empty()){
            int now=q.front().now,money=q.front().money,cnt=q.front().cnt;
            q.pop();
            if(cnt==n){
                ans=min(ans,money);
                continue;
            }
            for(auto i:a[now]){
                q.push({i.to,money+i.num,cnt+1});
            }
        }
        cout<<ans;
    }
    return 0;
}
