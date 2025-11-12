#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin); freopen(x".out","w",stdout); 
#define ll long long
#define eb emplace_back
const int N = 2e5 + 5;
const int M = 5e6 + 5;
string s[N],s2[N];
string t1,t2;
int n,q,sz[N],ans;
vector<int>nxt[N],nxt2[N];
unordered_map<int,bool>vis;
inline void solve(){
    cin>>t1>>t2; int len = t1.length(), len2 = t2.length();
    if(len != len2) return cout<<0<<'\n',void();
    t1 = ' ' + t1 ; t2 = ' ' + t2; ans = 0; 
    int L = 0,R = len + 1;
    while(L+1 <= len && t1[L+1] == t2[L+1]) L++;
    while(R-1 >= 1 && t1[R-1] == t2[R-1]) R--;
    for(int k = 1;k<=n;k++) {
        if(sz[k] > len) continue;
        vis.clear();
        for(int i=1,j=0;i<=len;i++){
            while(j && s[k][j+1] != t1[i]) j = nxt[k][j];
            if(s[k][j+1] == t1[i]) ++j;
            if(j == sz[k]) {
                vis[i-j+1] = 1;
                j = nxt[k][j] ;
            }
        }
        for(int i=1,j=0;i<=len2;i++){
            while(j && s2[k][j+1] != t2[i]) j = nxt2[k][j];
            if(s2[k][j+1] == t2[i]) ++j;
            if(j == sz[k]) {
                int l = i - j + 1;
                if(vis.count(l) && l <= L+1 && i >= R-1) ++ans;
                j = nxt2[k][j] ;
            }
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    FILE("replace");
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> q;
    for(int k=1;k<=n;k++) {
        cin>> s[k] >> s2[k] ;  sz[k] = s[k].length();
        s[k] = ' ' + s[k] ; s2[k] = ' ' + s2[k] ;
        nxt[k].resize(sz[k]+1);nxt2[k].resize(sz[k]+1);
        for(int i=2,j=0;i<=sz[k];i++){
            while(j && s2[k][j+1] != s2[k][i]) j = nxt2[k][j];
            if(s2[k][j+1] == s2[k][i]) ++j;
            nxt2[k][i] = j;
        }
        for(int i=2,j=0;i<=sz[k];i++){
            while(j && s[k][j+1] != s[k][i]) j = nxt[k][j];
            if(s[k][j+1] == s[k][i]) ++j;
            nxt[k][i] = j;
        }
    }
    while(q--) solve();
    return 0;
}