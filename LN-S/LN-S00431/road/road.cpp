#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=1e6+10;
vector<pii>g[N];
vector<int>d,d2;
int n,m,k,c[N],res,cnt;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        d.push_back(w);
    }
    for(int i=0;i<k;i++){
            int x;
        cin>>x;
    d2.push_back(x);
        for(int i=0;i<m;i++){
            cin>>c[i];
        }
    }
    if(k==0){
            int sum=0;
            sort(d.begin(),d.end());
            for(int i=0;i<d.size()/2;i++){
                sum+=d[i];
            }
        cout<<sum;
        return 0;
    }
    sort(d2.begin(),d2.end());
    for(auto t:d2){
        res+=t;
        cnt++;
        if(cnt>=k){
            cout<<res;
            return 0;
        }
    }
    return 0;
}
