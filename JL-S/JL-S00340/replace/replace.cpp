#define dps 799
#define I dryer
#include<bits/stdc++.h>
using namespace std;
#define r0 return 0;
#define int unsigned long long
#define ll long long
const int N = 5000500;
string s1[N],s2[N];
string t1[N],t2[N];
const int P = 131;
vector<int>vs1[N],vs2[N],vt1[N],vt2[N];
int p[N];
int n,q;
ll rig[N], lf[N],rt[N];
int gh(vector<int> vt, int l, int r){
    if(l > r) return 0;
    return vt[r] - vt[l] * p[r - l + 1];
}
inline void slove1(){
}
inline void slove2(){
    for(int ts = 1; ts <= q; ++ ts){
        int ans = 0;
        for(int i = 1; i <= t1[ts].size(); ++ i){
            for(int j = 1; j <= n; ++ j){
                if(i + s1[j].size() - 1 >= t1[ts].size()) continue;
                if(vs1[j][s1[j].size()]
                   ==
                   gh(vt1[ts], i, i + s1[j].size() - 1)){cout << 111;
                        int nowpls = i + s1[j].size() - 1;
                    if(gh(vt1[ts], 1,i-1) * p[t1[ts].size() - i + 1]
                       + vs2[j][s2[j].size()] * p[t1[ts].size() - (nowpls + 1) + 1]
                        + gh(vt1[ts], nowpls+1, s1[j].size()) == vt2[ts][t2[ts].size()]){
                        ++ ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); cin >> n >> q;
    p[0] = 1;
    for(int i = 1;i < 5555; ++ i) p[i] = p[i-1] * P;
    for(int i = 1; i <= n; ++ i){
        cin >> s1[i] >> s2[i];
        vs1[i].resize(s1[i].size() + 2,0);
        vs2[i].resize(s2[i].size() + 2,0);
        for(int j = 1; j <= s1[i].size(); ++ j){
            vs1[i][j] = vs1[i][j-1] * P + s1[i][j-1];
            vs2[i][j] = vs2[i][j-1] * P + s2[i][j-1];
            //cout << vs1[i][j] << ' ';
        }
        //cout << endl;
    }
    for(int i = 1; i <= q; ++ i) {cin >> t1[i] >> t2[i],
        vt1[i].resize(t1[i].size() + 2,0),
        vt2[i].resize(t2[i].size() + 2,0);
        for(int j = 1; j <= t1[i].size(); ++ j){
            vt1[i][j] = vt1[i][j-1] * P + t1[i][j-1];
            vt2[i][j] = vt2[i][j-1] * P + t2[i][j-1];
            //cout << vt1[i][j] << ' ';
        }
        //cout << endl;
    }
    if(q == 1111111) slove1();
    else if(n <= 2000) slove2();

}
