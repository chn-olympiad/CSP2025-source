#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+2;
int T,n;
int val[MAXN][4],r[4],ans;
vector<int> Minv[4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        r[3]=r[1]=r[2]=0;
        cin>>n;
        Minv[1].clear();
        Minv[2].clear();
        Minv[3].clear();
        for(int i=1;i<=n;i++){
            cin>>val[i][1]>>val[i][2]>>val[i][3];
            int t=3;
            if(val[i][1]>val[i][t]) t=1;
            if(val[i][2]>val[i][t]) t=2;
            int Min=0;
            for(int j=1;j<=3;j++){
                if(j==t) continue;
                Min=max(Min,val[i][j]);
            }
            Minv[t].push_back(val[i][t]-Min);
            r[t]++;
            ans+=val[i][t];
        }
        int t=1;
        if(r[2]>r[t]) t=2;
        if(r[3]>r[t]) t=3;
        if(r[t]*2<=n){
            cout<<ans<<'\n';
            continue;
        }
        sort(Minv[t].begin(),Minv[t].end());
        for(int i=0;i<r[t]-n/2;i++){
            ans-=Minv[t][i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}