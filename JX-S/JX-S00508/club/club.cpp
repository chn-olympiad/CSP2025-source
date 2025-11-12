#include<bits/stdc++.h>
#define il inline
#define reg register
#define rep(i,a,b) for(reg int (i)=(a);(i)<=(b);++(i))
#define drep(i,a,b) for(reg int (i)=(a);(i)>=(b);--(i))
#define pb push_back
#define ins insert
using namespace std;
const int N=1e5+10;
int a[N][3];
priority_queue<int>q[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int lim=n/2;
        int ans=0;
        rep(i,1,n){
            int maxn=-1,maxw=-1;
            rep(j,0,2){
                cin>>a[i][j];
                if(a[i][j]>maxn){
                    maxn=a[i][j];
                    maxw=j;
                }
            }
            int maxt=-0x7fffffff;
            rep(j,0,2){
                if(j!=maxw)maxt=max(maxt,-maxn+a[i][j]);
            }
            ans+=maxn;
            // cerr<<maxn<<' '<<maxt<<'\n';
            q[maxw].push(maxt);
            if(q[maxw].size()>lim){
                ans+=q[maxw].top();
                q[maxw].pop();
            }
        }
        cout<<ans<<'\n';
        rep(j,0,2)while(!q[j].empty())q[j].pop();
    }
    return 0;
}
// 2:30 -- 22:30