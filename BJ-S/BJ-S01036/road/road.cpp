#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,pair<int,int>> piii;
const int maxn=10015;
int n,m,k,p[maxn];
piii eg[1000005];
vector<piii> pg[15];
vector<int> uc;
struct bcj{
    int fa[maxn],siz[maxn];
    void clear(){
        for(int i=1;i<=n+k;++i)fa[i]=i,siz[i]=1;
    }
    int getf(int x){
        if(fa[x]==x)return x;
        return fa[x]=getf(fa[x]);
    }
    int Merge(int x,int y){
        x=getf(x);y=getf(y);
        if(x==y)return 0;
        if(siz[x]>siz[y])swap(x,y);
        fa[x]=y;
        siz[y]+=siz[x];siz[x]=0;
        return 1;
    }
}t1;
vector<piii> solve(int l,int r){
    if(l==r)return pg[uc[l]];
    int mid=l+r>>1;
    vector<piii> t1=solve(l,mid),t2=solve(mid+1,r);
    vector<piii> res(t1.size()+t2.size());
    merge(t1.begin(),t1.end(),t2.begin(),t2.end(),res.begin());
    return res;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i){
        int u,v,w;cin>>u>>v>>w;
        eg[i]=make_pair(w,make_pair(u,v));
    }
    sort(eg+1,eg+m+1);
    t1.clear();
    for(int i=1;i<=m;++i){
        int u=eg[i].second.first,v=eg[i].second.second;
        if(t1.Merge(u,v))pg[0].push_back(eg[i]);
    }
    for(int i=1;i<=k;++i){
        cin>>p[i];
        for(int j=1;j<=n;++j){
            int x;cin>>x;
            pg[i].push_back(make_pair(x,make_pair(i+n,j)));
        }
        sort(pg[i].begin(),pg[i].end());
    }
    long long ans=0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<(1<<k);++i){
        long long num=0;uc.clear();uc.push_back(0);
        for(int j=0;j<k;++j)if(i&(1<<j)){
            num+=p[j+1];
            uc.push_back(j+1);
        }
        t1.clear();
        vector<piii> tmp=solve(0,uc.size()-1);
        for(int i=0;i<tmp.size();++i){
            if(t1.Merge(tmp[i].second.first,tmp[i].second.second)){
                num+=tmp[i].first;
            }
        }
        ans=min(ans,num);
    }
    cout<<ans;
    return 0;
}