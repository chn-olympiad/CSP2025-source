#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> pq[3];
vector<pair<int,int> > tmp;
const int N=1e5;
int a[N+5][3],id[N+5][3],b[3];
void solve(){
    cin>>n;
    for(int i=0;i<3;i++){
        pq[i].clear();
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        b[0]=a[i][0];
        b[1]=a[i][1];
        b[2]=a[i][2];
        id[i][0]=0;
        id[i][1]=1;
        id[i][2]=2;
        sort(id[i],id[i]+3,[](int x,int y){
             return b[x]>b[y];
        });
        pq[id[i][0]].emplace_back(i);
        ans+=a[i][id[i][0]];
    }
    int mx=0;
    for(int i=0;i<3;i++) mx=max(mx,(int)pq[i].size());
    if(mx>(n>>1)){
        int p;
        for(int i=0;i<3;i++){
            if(pq[i].size()==mx){
                p=i;
                break;
            }
        }
        tmp.clear();
        for(int i:pq[p]){
            tmp.push_back({max(a[i][(p+2)%3],a[i][(p+1)%3])-a[i][p],i});
        }
        sort(tmp.begin(),tmp.end());
        for(int i=(n>>1);i<tmp.size();i++){
            ans+=tmp[i].first;
        }
    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int Tcases=1;
    cin>>Tcases;
    while(Tcases--) solve();
    return 0;
}
