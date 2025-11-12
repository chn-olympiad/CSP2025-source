/*

       2025.11.1

 * Happy Zenith Noises *

*/
#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
using namespace std;
const int MAXN=1000005,inf=0x3f3f3f3f3f3f3f3f;
typedef pair<int,int>P;
int n,ans;
P a[MAXN][4];
bool cmp(P x,P y){return x>y;}
void solve(){
    priority_queue<int,vector<int>,greater<int> >q[4];
    cin>>n;ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][1].fi>>a[i][2].fi>>a[i][3].fi;
        a[i][1].se=1,a[i][2].se=2,a[i][3].se=3;
        sort(a[i]+1,a[i]+1+3,cmp);
        int t=a[i][1].se;
        if(q[t].size()==n/2){
            if(a[i][1].fi-a[i][2].fi>q[t].top()){
                ans+=a[i][1].fi-q[t].top();q[t].pop();
                q[t].push(a[i][1].fi-a[i][2].fi);
            }
            else q[a[i][2].se].push(0),ans+=a[i][2].fi;
        }
        else{
            q[t].push(a[i][1].fi-a[i][2].fi);
            ans+=a[i][1].fi;
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(nullptr);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;cin>>T;
    while(T--)solve();
    return 0;
}
