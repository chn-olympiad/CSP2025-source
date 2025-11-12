#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,a[100005][4];
vector<int> b[4];
int change(int i){
    int maxx=max({a[i][1],a[i][2],a[i][3]});
    if(a[i][1]==maxx)return maxx-max(a[i][2],a[i][3]);
    else if(a[i][2]==maxx)return maxx-max(a[i][1],a[i][3]);
    else return maxx-max(a[i][1],a[i][2]);
}
bool cmp(int x,int y){
    return change(x)<change(y);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            int maxx=max({a[i][1],a[i][2],a[i][3]});
            ans+=maxx;
            if(a[i][1]==maxx)b[1].push_back(i);
            else if(a[i][2]==maxx)b[2].push_back(i);
            else b[3].push_back(i);
        }
        int maxx=max({b[1].size(),b[2].size(),b[3].size()});
        if(maxx<=n/2){
            cout<<ans<<"\n";
        }
        else{
            int bh;
            if(b[1].size()==maxx)bh=1;
            else if(b[2].size()==maxx)bh=2;
            else bh=3;
            sort(b[bh].begin(),b[bh].end(),cmp);
            for(int i=0;i<b[bh].size()-n/2;i++)ans-=change(b[bh][i]);
            cout<<ans<<"\n";
        }
        b[1].clear(),b[2].clear(),b[3].clear();
    }
    return 0;
}
