#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5,M = 1e6 + 5;
long long n,q,ans;
string s1[N],s2[N];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    if((n <= 1000 && q <= 1000) || q == 1){
        for(int i = 1; i <= n; ++i){
            cin >> s1[i] >> s2[i];
        }
        for(int o = 1; o <= q; ++o){
            string s,t;
            cin >> s >> t;
            for(int i = 1; i <= n; ++i){
                for(int j = 0; j < s.size() - s1[i].size() + 1; ++j){
                    if(s[j] == s1[i][0]){//i don't know how to use kmp.
                        bool ok = 1;
                        for(int l = 1; l < s1[i].size(); ++l){
                            if(s[j + l] != s1[i][l]){
                                ok = 0;
                                break;
                            }
                        }
                        if(ok){
                            string tt = "";
                            for(int k = 0; k < j; ++k){
                                tt = tt + s[k];
                            }
                            tt = tt + s2[i];
                            for(int k = j + s1[i].size(); k < s.size(); ++k){
                                tt = tt + s[k];
                            }
                            if(tt == t)ans++;
                        }
                    }
                }
            }
            cout << ans << '\n';
            ans = 0;
        }
    }else{
        int g[N] = {0},le[N] = {0};
        for(int i = 1; i <= n; ++i){
            cin >> s1[i] >> s2[i];

            int a = -1,b = -1;
            char ch = '0';
            if(s1[i][0] == s1[i][1])ch = s1[i][0];
            if(s1[i][1] == s1[i][2])ch = s1[i][1];
            if(s1[i][0] == s1[i][2])ch = s1[i][0];
            int len = s1[i].size();
            le[i] = len;
            for(int j = 0; j < len; ++j){
                if(s1[i][j] != s2[i][j]){
                    if(a == -1){
                        if(s1[i][j] == ch){
                            a = j;
                        }else{
                            b = j;
                        }
                    }else{
                        if(s1[i][j] == ch){
                            a = j;
                        }else{
                            b = j;
                        }
                    }
                }
            }
            int xj = b - a;
            g[i] = xj;
        }
        for(int o = 0; o <= q; ++o){
            string s,t;
            cin >> s >> t;

            int a = -1,b = -1;
            char ch = '0';
            if(s[0] == s[1])ch = s[0];
            if(s[1] == s[2])ch = s[1];
            if(s[0] == s[2])ch = s[0];
            for(int j = 0; j < s.size(); ++j){
                if(s[j] != t[j]){
                    if(a == -1){
                        if(s[j] == ch){
                            a = j;
                        }else{
                            b = j;
                        }
                    }else{
                        if(s[j] == ch){
                            a = j;
                        }else{
                            b = j;
                        }
                    }
                }
            }
            int xj = b - a;
            for(int i = 1; i <= n; ++i){
                if(g[i] == xj && le[i] <= s.size())ans++;
            }
            cout << ans << '\n';
            ans = 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
