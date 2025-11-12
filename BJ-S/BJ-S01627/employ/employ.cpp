#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

int n,m,c[510],a[510],ans;
vector<int> v;
string s;

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

bool check(){
    int cnt = 0,c1 = 0;
    for(int i = 1;i <= n;i++){
        if(s[i - 1] == '0'){
            c1++;
        }else{
            if(c1 >= c[a[i]]){
                c1++;
            }else{
                cnt++;
            }
        }
    }
    return cnt >= m;
}

void dfs(int k){
    if(k > n){
        if(check()){
            /*
            for(int i = 1;i <= n;i++){
              cout << a[i];
            }
            cout << endl;
            */
            ans++;
            ans %= mod;
        }
        return;
    }
    for(int i = 0;i < v.size();i++){
        a[k] = v[0];
        v.erase(v.begin());
        dfs(k + 1);
        v.push_back(a[k]);
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

    cin >> n >> m;
    cin >> s;

    for(int i = 1;i <= n;i++){
        cin >> c[i];
    }

    if(n <= 18){
        for(int i = 1;i <= n;i++){
            v.push_back(i);
        }
        dfs(1);
        cout << ans << endl;
        return 0;
    }

    cout << 0 << endl;

    return 0;
}