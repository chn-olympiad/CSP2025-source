#include <bits/stdc++.h>
#include <cstring>
#include <string>

using namespace std;
#define ll long long
int n,m;
string s[200050][3];
string q[200050][3];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> s[i][0] >> s[i][1];
    }
    for (int i=1;i<=m;i++){
        cin >> q[i][0] >> q[i][1];
    }
    ll ans=0;
    string tem;
    for (int i=1;i<=m;i++){
        ans=0;
        for (int j=1;j<=n;j++){
            if (q[i][0].length()<s[j][0].length()) continue;
            auto x = q[i][0].find(s[j][0]);
            auto y = q[i][1].find(s[j][1]);
            if (x==y && x<=q[i][0].length() && y<=q[i][1].length()){
                    if (x+s[j][0].length() > q[i][0].length()) continue;
                bool flag=1;
                for (int p=x+s[j][0].length();p<q[i][0].length();p++){
                    if (q[i][0][p] != q[i][1][p]){
                        flag = 0;
                        break;
                    }
                }
                if (flag) ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
