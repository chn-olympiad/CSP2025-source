#include<bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define updl(x,y) ((x)<(y)?(x):(x) = (y))
#define updg(x,y) ((x)>(y)?(x):(x) = (y))
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back

#define debug
int n;
priority_queue<int> q[3];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int __T__ = 1;
#ifdef debug
    cin >> __T__;
#endif // debug
    while(__T__--){
        for(int i = 0;i<3;i++) while(!q[i].empty()) q[i].pop();
        cin >> n;
        int ans = 0;
        for(int i = 1,x,y,z;i<=n;i++){
            cin >> x >> y >> z;
            if(x>y&&x>z) q[0].push(max(y,z)-x),ans+=x;
            else if(y>z) q[1].push(max(x,z)-y),ans+=y;
            else q[2].push(max(x,y)-z),ans+=z;
        }
        for(int i = 0;i<3;i++) while(q[i].size()>n/2) ans+=q[i].top(),q[i].pop();
        cout << ans << '\n';
    }
    return 0;
}
