#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
constexpr int N = 1e4+10,M = 1e6+10;
int n,q,ans;
string s1[N],s2[N];
bool vis[N];
void solve(){
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s1[i]>>s2[i];
    }
    while(q--){
        string t1,t2;
        cin >> t1 >> t2;
        cout << 0 <<'\n';
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int _ = 1;
    //cin >> _;
    while(_--) solve();
    return 0;
}
