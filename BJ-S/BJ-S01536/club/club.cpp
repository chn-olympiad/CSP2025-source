#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define ll long long
const int maxn=1e5+10;
int n; ll ans;
pair<int,int> ai[maxn][3];
vector<int> pos[maxn];

int main(){
freopen("club.in", "r", stdin);
freopen("club.out", "w", stdout);
    int T; cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>ai[i][0].first>>ai[i][1].first>>ai[i][2].first;
            ai[i][0].second=0; ai[i][1].second=1; ai[i][2].second=2;
            sort(ai[i],ai[i]+3,greater<pair<int,int>>());
            ans+=ai[i][0].first;
            pos[ai[i][0].second].push_back(ai[i][0].first-ai[i][1].first);
        }
        int mx=-1;
        for(int i=0;i<3;i++)if(pos[i].size()>n/2)mx=i;
        if(mx!=-1){
            sort(pos[mx].begin(),pos[mx].end());
            for(int i=0;i<pos[mx].size()-n/2;i++)ans-=pos[mx][i];
        }
        cout<<ans<<endl;
        pos[0].clear(); pos[1].clear(); pos[2].clear(); ans=0;
    }
}