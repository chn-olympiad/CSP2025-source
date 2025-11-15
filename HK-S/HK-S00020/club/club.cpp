#include <bits/stdc++.h>
#define int long long
#define list list_
using namespace std;

int t,n,a[1021000][4],x,cnt=0;
vector<int> list[4];
vector<pair<pair<int,int>,int> > nlist;

void solve(){
    cin>>n;
    cnt=0; x=0;
    for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
    for(int i=1;i<=3;i++)list[i].clear(), nlist.clear();
    for(int i=1;i<=n;i++){
        if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])list[1].push_back(i);
        else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])list[2].push_back(i);
        else list[3].push_back(i);
    }
    if(list[1].size() > n/2){
        x=1;
        for(auto i:list[1]){
            if(a[i][2]>a[i][3])nlist.push_back({{a[i][1]-a[i][2],i},a[i][2]});
            else nlist.push_back({{a[i][1]-a[i][3],i},a[i][3]});
        }
    }
    if(list[2].size() > n/2){
        x=2;
        for(auto i:list[2]){
            if(a[i][3]>a[i][1])nlist.push_back({{a[i][2]-a[i][3],i},a[i][3]});
            else nlist.push_back({{a[i][2]-a[i][1],i},a[i][1]});
        }
    }
    if(list[3].size() > n/2){
        x=3;
        for(auto i:list[3]){
            if(a[i][1]>a[i][2])nlist.push_back({{a[i][3]-a[i][1],i},a[i][1]});
            else nlist.push_back({{a[i][3]-a[i][2],i},a[i][2]});
        }
    }
    sort(nlist.begin(), nlist.end());
    if(x>0){
        for(int i=0;i<list[x].size();i++){
            if(i<list[x].size()-n/2)cnt+=nlist[i].second;
            else cnt+=a[nlist[i].first.second][x];
        }
    }
    for(int i=1;i<=3;i++){
        if(i==x)continue;
        for(auto j:list[i])cnt+=a[j][i];
    }
    cout<<cnt<<"\n";
}

signed main(){
    freopen("club.in", "r", stdin); freopen("club.out", "w", stdout);
    cin>>t;
    while(t--) solve();
    return 0;
}