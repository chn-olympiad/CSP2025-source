#include<bits/stdc++.h>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define updl(x,y) ((x)<(y)?(x):(x = y))
#define updg(x,y) ((x)>(y)?(x):(x = y))
#define rep(i,s,t) for(int i = s;i<=t;i++)
#define rep(i,s,t,step) for(int i = s;i<=t;i+=step)
#define per(i,s,t) for(int i = s;i>=t;i++)
#define per(i,s,t,step) for(int i = s;i>=t;i-=step)
#define pii pair<int,int>
#define fir first
#define sec second
#define pb push_back
#define eb emplace_back
#define maxn 500005
#define maxm

// #define debug
int n,k,a[maxn];
map<int,bool> mp;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int __T__ = 1;
#ifdef debug
    cin >> __T__;
#endif // debug
    while(__T__--){
        cin >> n >> k;
        int qwq = 0,ans = 0;
        mp[0] = 1;
        for(int i = 1,x;i<=n;i++){
            cin >> x;
            qwq^=x;
            if(mp[qwq^k]){
                mp.clear();
                mp[0] = 1;
                ans++;
                qwq = 0;
            }else mp[qwq] = 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
