#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,s,t) for(ll i = s;i <= t;++i)
#define per(i,t,s) for(ll i = t;i >= s;--i)
const ll N = 1e5 + 5;
string s = "";
string t = "";
inline void openfile(string s)
{
    freopen((s + ".in").c_str(),"r",stdin);
    freopen((s + ".out").c_str(),"w",stdout);
}
inline void closefile()
{
    fclose(stdin);
    fclose(stdout);
}
int main()
{
    openfile("number");
    cin >> s;
    rep(i,0,(ll)(s.size()) - 1)
        if(isdigit(s[i]))
            t += s[i];
    s = t;
    sort(s.begin(),s.end());
    reverse(s.begin(),s.end());
    while(s[0] == '0' && (ll)(s.size()) > 1)
        s.erase(0,1);
    cout << s;
    closefile();
    return 0;
}
