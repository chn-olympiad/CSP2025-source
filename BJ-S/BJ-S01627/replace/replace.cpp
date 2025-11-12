#include<bits/stdc++.h>
using namespace std;
#define int long long

const int base = 10001;
const int mod = 998244353;

int n,q,hashdiff1[5000010],hashdiff2[5000010],po[5000010],ha[5000010],f[200010],l[200010];
vector<int> has[5000010];

int read(){
    char c;
    int k = 0,f = 1;
    c = getchar_unlocked();
    while(c > '9' || c < '0'){
        if(c == '-'){
            f = -1;
        }
        c = getchar_unlocked();
    }
    while('0' <= c && c <= '9'){
        k = k * 10 + c - '0';
        c = getchar_unlocked();
    }
    return k * f;
}

int gethash(int k,int l,int r){
    if(l > r){
        return 0;
    }
    if(l == 0){
        return has[k][r];
    }
    return ((has[k][r] - has[k][l - 1] * po[r - l + 1]) % mod + mod) % mod;
}

int gethash1(int l,int r){
    if(l == 0){
        return ha[r];
    }
    return ((ha[r] - ha[l - 1] * po[r - l + 1]) % mod + mod) % mod;
}

signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    po[0] = 1;
    for(int i = 1;i <= 5000000;i++){
        po[i] = po[i - 1] * base;
        po[i] %= mod;
    }

    cin >> n >> q;

    for(int i = 1;i <= n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        int h = 0;
        f[i] = -1;
        l[i] = -2;
        for(int j = 0;j < s1.size();j++){
            h = h * base + s1[j];
            h %= mod;
            has[i].push_back(h);
            if(s1[j] != s2[j]){
                if(f[i] == -1){
                    f[i] = j;
                }
                l[i] = j;
            }
        }
//        cout << f[i] << " " << l[i] << endl;
        hashdiff1[i] = gethash(i,f[i],l[i]);
        h = 0;
        for(int j = f[i];j <= l[i];j++){
            h = h * base + s2[j];
            h %= mod;
        }
        hashdiff2[i] = h;
    }

    while(q--){
        string t1,t2;
        cin >> t1 >> t2;
        int h = 0,fi = -1,la = -2,ans = 0;
        for(int j = 0;j < t1.size();j++){
            h = h * base + t1[j];
            h %= mod;
            ha[j] = h;
            if(t1[j] != t2[j]){
                if(fi == -1){
                    fi = j;
                }
                la = j;
            }
        }
//        cout << fi << " " << la << endl;
        h = 0;
        for(int j = fi;j <= la;j++){
            h = h * base + t2[j];
            h %= mod;
        }
        int difhash = gethash1(fi,la);
        for(int i = 1;i <= n;i++){
            if(hashdiff1[i] == difhash && h == hashdiff2[i]){
                if(f[i] > fi || has[i].size() - l[i] > t1.size() - la){
                    continue;
                }
                if(gethash(i,0,has[i].size() - 1) == gethash1(fi - f[i],la + has[i].size() - 1 - l[i])){
                    ans++;
//                    cout << q << " " << i << " " << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}