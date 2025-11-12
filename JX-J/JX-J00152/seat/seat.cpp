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

// #define debug
int n,m,a[105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int __T__ = 1;
#ifdef debug
    cin >> __T__;
#endif // debug
    while(__T__--){
        cin >> n >> m >> a[1];
        int qwq = a[1],awa = 0;
        for(int i = 2,x;i<=n*m;i++) cin >> x,awa+=(x>qwq);
        int column = awa/n+1;
        int row;
        if(column&1) row = awa%n+1;
        else row = n-awa%n;
        cout << column << ' ' << row << '\n';
    }
    return 0;
}
