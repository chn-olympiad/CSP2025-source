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
#define n
#define m

// #define debug
string s,t,tmp = " ";

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int __T__ = 1;
#ifdef debug
    cin >> __T__;
#endif // debug
    while(__T__--){
        cin >> s;
        for(auto ch:s)
            if('0'<=ch&&ch<='9')
                tmp[0] = ch,t+=tmp;
        sort(t.begin(),t.end(),greater<char>());
        if(!t.size()) cout << "0\n";
        else if(t[0]=='0') cout << "0\n";
        else cout << t << '\n';
    }
    return 0;
}
