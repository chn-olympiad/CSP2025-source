#include <bits/stdc++.h>
using namespace std;

const int NR = 2e5 + 5;
string s1[NR], s2[NR];
string t1, t2;
int n, q, st, ed, nxt[NR], po[NR];

const int mod = 1e9 + 7, p = 119;
int gethash(string s){
    int ret = 0;
    for(int i = 0; i < s.size(); i ++){
        ret = (ret*p%mod+s[i]-'a'+1) % mod;
    }
    return ret;
}
int hashs1[NR], hashs2[NR];
int hasht1[NR], hasht2[NR];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> s1[i] >> s2[i];
        hashs1[i] = gethash(s1[i]);
        hashs2[i] = gethash(s2[i]);
        //s1[i] = ' ' + s1[i];
        //s2[i] = ' ' + s2[i];
    }
    po[0] = 1;
    for(int i = 1; i <= n; i ++) po[i] = po[i-1]*p%mod;
    while(q--){
        int ans = 0;
        cin >> t1 >> t2;
        t1 = ' ' + t1, t2 = ' ' + t2;
        int len = t1.size()-1;
        for(int i = 1; i <= len; i ++){
            hasht1[i] = (hasht1[i-1]*p%mod+t1[i]-'a'+1) % mod;
            hasht2[i] = (hasht2[i-1]*p%mod+t2[i]-'a'+1) % mod;
        }
        for(int i = 1; i <= len; i ++){
            if(t1[i] != t2[i]){
                st = i;
                break;
            }
        }
        for(int i = len; i >= 1; i --){
            if(t1[i] != t2[i]){
                ed = i;
                break;
            }
        }
        for(int x = 1; x <= n; x ++){
            string a = s1[x], b = t1;
            int lena = a.size(), lenb = b.size()-1;
            a = ' ' + a;
            for(int i = 0; i <= lena; i ++) nxt[i] = 0;
            for(int i = 2, j = 0; i <= lena; i ++){
                while(j > 0 && a[i] != a[j+1]){
                    j = nxt[j];
                }
                if(a[i] == a[j+1]) j ++;
                nxt[i] = j;
            }
            for(int i = 1, j = 0; i <= lenb; i ++){
                while(j > 0 && b[i] != a[j+1]){
                    j = nxt[j];
                }
                if(b[i] == a[j+1]) j ++;
                if(lena == j){
                    //cout << x << ' ' << "(i, j): " << i-j+1 << ' ' << i << endl;
                    //cout << st << ' ' << ed << endl;
                    //cout << t1.substr(i-j+1, j) << ' ' << s1[x] << endl;
                    //cout << t2.substr(i-j+1, j) << ' ' << s2[x] << endl;
                    //cout << "i-j+1 <= st && i >= ed: " << (i-j+1 <= st && i >= ed) << endl;
                    //cout << "t1.substr(i-j+1, j) == s1[x]" << (t1.substr(i-j+1, j) == s1[x]) << endl;
                    //cout << "t2.substr(i-j+1, j) == s2[x]" << (t2.substr(i-j+1, j) == s2[x]) << endl;

                    int tmp1 = ((hasht1[i]-hasht1[i-j]*po[j]%mod)%mod+mod)%mod;
                    int tmp2 = ((hasht2[i]-hasht2[i-j]*po[j]%mod)%mod+mod)%mod;
                    if(i-j+1 <= st && i >= ed && tmp1 == hashs1[x] && tmp2 == hashs2[x]){
                        ans ++;
                    }
                    j = nxt[j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
