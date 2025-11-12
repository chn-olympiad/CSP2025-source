#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[1000005][3],pos[1000005],POS[1000005];
priority_queue<int,vector<int>,greater<int> > pq[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i][0]>>a[i][1]>>a[i][2],pos[i]=POS[i]=-1;
        for(int i=0; i<3; i++) while(!pq[i].empty()) pq[i].pop();
        int ans=0;
        for(int i=1; i<=n; i++){
            for(int j=0; j<3; j++){
                if(pos[i]==-1||a[i][pos[i]]<a[i][j]) POS[i]=pos[i],pos[i]=j;
                else if(POS[i]==-1||a[i][POS[i]]<a[i][j]) POS[i]=j;
            }
            pq[pos[i]].push(a[i][pos[i]]-a[i][POS[i]]),ans+=a[i][pos[i]];
            if(pq[pos[i]].size()>n/2) ans-=pq[pos[i]].top(),pq[pos[i]].pop();
        }
        cout<<ans<<'\n';
    }
    return 0;
}