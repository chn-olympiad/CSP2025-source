#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<string, string> PSS;

const int N = 200010;

int n, q, tot;
int id[N];
string pre[N], suf[N];
map<PSS, int> ma;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int len = s1.size();
        int l, r;
        for(l = 0; l < len; l++)
            if(s1[l] != s2[l])
                break;
        for(r = len - 1; r >= 0; r--)
            if(s1[r] != s2[r])
                break;
        string ss1, ss2;
        if(s1 == s2){
            ss1 = ss2 = "";
        }else{
            ss1 = s1.substr(l, r - l + 1);
            ss2 = s2.substr(l, r - l + 1);
            pre[i] = s1.substr(0, l);
            suf[i] = s2.substr(r + 1, len - r - 1);
        }
        PSS idx = make_pair(ss1, ss2);
        if(!ma[idx]) ma[idx] = ++tot;
        id[i] = ma[idx];
        //cout << ss1 << " " << ss2 <<"\n";
    }
    string nowpre, nowsuf;
    for(int i = 1; i <= q; i++){
        string s1, s2;
        cin >> s1 >> s2;
        int len = s1.size();
        if(len != s2.size()){
            cout << "0\n";
            continue;
        }
        int l, r;
        for(l = 0; l < len; l++)
            if(s1[l] != s2[l])
                break;
        for(r = len - 1; r >= 0; r--)
            if(s1[r] != s2[r])
                break;
        string ss1, ss2;
        if(s1 == s2){
            ss1 = ss2 = "";
        }else{
            ss1 = s1.substr(l, r - l + 1);
            ss2 = s2.substr(l, r - l + 1);
            nowpre = s1.substr(0, l);
            nowsuf = s2.substr(r + 1, len - r - 1);
        }
        PSS idx = make_pair(ss1, ss2);
        if(!ma[idx]){
            cout << "0\n";
            continue;
        }
        int nowid = ma[idx];
        int ans = 0;
        for(int j = 1; j <= n; j++){
            if(nowid != id[j]) continue;
            if(pre[j].size() > nowpre.size()) continue;
            if(suf[j].size() > nowsuf.size()) continue;
            string tmppre = nowpre.substr(nowpre.size() - pre[j].size(), pre[j].size());
            string tmpsuf = nowsuf.substr(0, suf[j].size());
            if(tmppre != pre[j]) continue;
            if(tmpsuf != suf[j]) continue;
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}
