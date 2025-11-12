#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e4+2,MAXM=1e6+2,MAXK=11;
const ll inf=1e18;
struct edge{
    int u,v,w;
    bool operator < (const edge _) const {
        return w>_.w;
    }
};
struct addp{
    int i;
    ll val;
    bool operator < (const addp _) const {
        return val>_.val;
    }
};
int n,m,k;
int u[MAXM],v[MAXM];
int f[MAXN];
vector<int> vec[MAXN];
ll w[MAXM],val[MAXK][MAXN],cst[MAXK],poi[MAXK],sum[MAXK],num[MAXK];
ll ans=0;
bool used[MAXK];
bool findx[MAXK][MAXN];
priority_queue<edge> pq1;
priority_queue<addp> pq2[MAXK];
int F(int x){
    if(f[x]==x) return x;
    else return f[x]=F(f[x]);
}
bool merge(int x,int y){
    x=F(x),y=F(y);
    if(x==y) return 0;
    //if(vec[x].size()>vec[y].size()) swap(x,y);
    //for(auto i:vec[x]){
    //    vec[y].push_back(x);
    //}
    //vec[x].clear();
    //vec[x].shrink_to_fit();
    f[x]=y;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int j=1;j<=m;j++){
        cin>>u[j]>>v[j]>>w[j];
        pq1.push(edge{u[j],v[j],w[j]});
    }
    for(int j=1;j<=k;j++){
        cin>>cst[j];
        int Min=0;
        val[j][0]=inf;
        for(int i=1;i<=n;i++){
            cin>>val[j][i];
            if(val[j][i]<val[j][Min]) Min=i;
        }
        for(int i=1;i<=n;i++){
            if(i==Min) continue;
            pq2[j].push(addp{i,val[j][i]});
        }
        cst[j]+=val[j][Min];
        poi[j]=Min;
    }
    for(int i=1;i<=n;i++){
        f[i]=i;
        vec[i].push_back(i);
    }
    int cnt=0;
    while(cnt!=n-1){
        ll v1=pq1.top().w;
        for(int j=1;j<=k;j++){
            if(used[j]) continue;
            while(pq2[j].size()&&pq2[j].top().val<=v1){
                sum[j]+=pq2[j].top().val;
                num[j]++;pq2[j].pop();
            }
            /*
            int fj=F(poi[j]);
            for(auto x:vec[fj]){
                if(x!=poi[j]&&!findx[j][x]&&val[j][x]<=v1){
                    sum[j]-=val[j][x];
                    num[j]--;
                }
            }*/
            if(cst[j]*num[j]+sum[j]<=v1*num[j]&&num[j]!=0){
                ans+=cst[j];
                used[j]=1;
                for(int i=1;i<=n;i++){
                    if(i==poi[j]) continue;
                    pq1.push(edge{poi[j],i,val[j][i]});
                }
            }
        }
        int u=pq1.top().u,v=pq1.top().v;
        v1=pq1.top().w;
        if(merge(u,v)){
            cnt++;
            ans+=v1;
        }
        pq1.pop();
    }
    cout<<ans<<'\n';
    return 0;
}
