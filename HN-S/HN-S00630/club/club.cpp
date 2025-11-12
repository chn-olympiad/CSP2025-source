#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

inline void read(int &x){
    x=0;bool f=false;char c=getchar();
    while(c>'9'||c<'0'){if(c=='-')f=true;c=getchar();}
    while(c<='9'&&c>='0'){x=(x<<3)+(x<<1)+(c-'0');c=getchar();}
    x=f?-x:x;return ;
}
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>10) write(x/10);
    putchar('0'+x%10);
    return ;
}
inline void print(int x){write(x);putchar('\n');}

const int N = 5e5 + 10, mod = 998244353;
const int inf = 2e18;

priority_queue<int> q[3];
int t;
int n;
pii a[N][3];

void solve(){
    read(n);int ans = 0;
    for(int i = 1; i <= 3; i++) while(!q[i].empty()) q[i].pop();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 3; j++) read(a[i][j].fi), a[i][j].se = j;
        sort(a[i] + 1, a[i] + 4);
        q[a[i][3].se].push(a[i][2].fi - a[i][3].fi);ans += a[i][3].fi;
    }
    for(int i = 1; i <= 3; i++){
        if(q[i].size() > n / 2){
            while(q[i].size() > n / 2) ans += q[i].top(), q[i].pop();
        }
    }
    print(ans);
}

signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    read(t);
    while(t--) solve();
    return 0;
}