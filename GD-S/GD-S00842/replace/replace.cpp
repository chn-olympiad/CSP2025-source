#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define ROF(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define int long long
using namespace std;
const int N = 2e5+20;
// const int M = 5e6+5;
const int mod = 1e9+7;
const int P = 131;
int n,q;
string s[N][3],t[3];
signed main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>n>>q;
    FOR(i,1,n) {
        cin>>s[i][1]>>s[i][2];
    }
    while(q--) {
        cin>>t[1]>>t[2];
        if(t[1].size() != t[2].size()) {
            printf("0\n");
            continue;
        }
        unsigned long long h1=0, h2=0;
        int ans = 0, len = t[1].size();
        for(int i=0; i<t[1].size(); i++) {
            FOR(j,1,n) {
                int len2 = s[j][1].size();
                if(s[j][1].size() > len-i) continue;
                if(t[1].substr(i,len2) != s[j][1]) continue; 
                if(t[1].substr(0,i)+s[j][2]+t[1].substr(i+len2) == t[2]) ans++;
            }
            h1 = h1*P+t[1][i]-'a';
            h2 = h2*P+t[2][i]-'a';
            if(h1 != h2) break;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
