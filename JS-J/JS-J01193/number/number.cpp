#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);(i)<=(r);++(i))
#define rep1(i,l,r) for(int i=(l);(i)<(r);++(i))
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define il inline
#define cst const
#define csti const int
#define pii pair<int,int>
#define mkp make_pair
#define fi first
#define se second
#define eb emplace_back
//#define int long long
//#define LLL

#ifdef LLL
csti inf=0x3f3f3f3f3f3f3f3fll;
#else
csti inf=0x3f3f3f3f;
#endif // LLL

csti N=1e6+7,mod=1;

using namespace std;
vector<int> g;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;cin>>s;
    rep1(i,0,s.size()){
        if(isdigit(s[i])){
            g.eb(s[i]);
        }
    }
    sort(g.begin(),g.end());
    reverse(g.begin(),g.end());
    for(csti y:g){
        cout<<char(y);
    }cout<<'\n';
    return 0;
}
