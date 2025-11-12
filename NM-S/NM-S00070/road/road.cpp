#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<tuple<int,int,int> > adj;
struct DSU{
    int size;
    vector<int> fa;
    DSU(int size){
        fa.resize(size+5);
        for(int i=0;i<=size;i++){
            fa[i]=i;
        }
    }
    int find(int x){
        if(x==fa[x])return x;
        else return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        fa[find(x)]=fa[find(y)];
    }
};
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        adj.emplace_back(z,x,y);
    }
    vector<tuple<int,int,int> > adj2[15];
    vector<int> val(15);
    bool flag=1;
    for(int i=0;i<k;i++){
        int cost;
        cin>>cost;
        if(cost!=0)flag=0;
        val[i]=cost;
        if(cost==0){
            for(int j=1;j<=n;j++){
                int tmp;
                cin>>tmp;
                adj.emplace_back(tmp,j,i+n+1);
            }
        }
        else{
            for(int j=1;j<=n;j++){
                int tmp;
                cin>>tmp;
                adj2[i].emplace_back(tmp,j,i+n+1);
            }
        }
    }
    int ans=0x3f3f3f3f;
    if(flag==0){
        for(int i=0;i<(1<<k);i++){
            auto adj3=adj;
            int sum=0;
            for(int j=0;j<k;j++){
                if(i&(1<<j)){
                    sum+=val[j];
                    for(auto tmp:adj2[j]){
                        adj3.emplace_back(tmp);
                    }
                }
            }
            sort(adj3.begin(),adj3.end());
            DSU dsu(n+k+1);
            for(auto i:adj3){
                auto [x,y,z]=i;
                if(dsu.find(y)!=dsu.find(z)){
                    //cout<<x<<" "<<y<<" "<<z<<"\n";
                    dsu.merge(y,z);
                    sum+=x;
                }
            }
            //cout<<"\n";
            ans=min(ans,sum);
        }
    }
    else{
        int i=(1<<k)-1;
        int sum=0;
        for(int j=0;j<k;j++){
            for(auto tmp:adj2[j]){
                adj.emplace_back(tmp);
            }
        }
        sort(adj.begin(),adj.end());
        DSU dsu(n+k+1);
        for(auto i:adj){
            auto [x,y,z]=i;
            if(dsu.find(y)!=dsu.find(z)){
                //cout<<x<<" "<<y<<" "<<z<<"\n";
                dsu.merge(y,z);
                sum+=x;
            }
        }
        //cout<<"\n";
        ans=min(ans,sum);
    }
    cout<<ans;
    return 0;
}
