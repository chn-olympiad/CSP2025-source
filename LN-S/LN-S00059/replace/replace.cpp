#include <bits/stdc++.h>
using namespace std;

int n,q;
string s[200010][3]; int len[200010];

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1; i<=n; ++i){
        cin >> s[i][1] >> s[i][2];
        len[i] = s[i][1].size();
    }
    while(q--){
        string s1,s2;
        cin >> s1 >> s2;
        int slen = s1.size();
        long long ans = 0;
        for(int i = 0; i<slen; ++i){
            for(int j = 1; j<=n; ++j){
                if(i+len[j]-1<slen){
                    if(s1.substr(i,len[j])==s[j][1]){
                        if(s1.substr(0,i)+s[j][2]+s1.substr(i+len[j],slen-i-len[j]+1)==s2) ++ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
