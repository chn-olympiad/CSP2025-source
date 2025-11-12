#include<bits/stdc++.h>
#define ll long long
#define fr first
#define sc second
#define pii pair<ll,ll>
using namespace std;
int cnt[10];
string s;
void solve(){
    cin >> s;
    for(char ch : s) 
        if(isdigit(ch)) cnt[ch-'0']++;
    for(int i = 9; i >= 0; --i)
        for(int j = 0; j < cnt[i]; ++j)
            cout << i;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    solve();
    return 0;
}
//const int N = 114514;
/*struct BIT{
    int tr[N], len;
    inline int lowbit(int x){ return x & (-x); }
    inline void cl(int x){
        len = x + 10;
        memset(tr, 0, sizeof(tr));
    }
    inline void add(int x, ll y){
        for(int i = x; i <= len; i += lowbit(i)) tr[i] += y;
    }
    inline ll ask(int x){
        ll res = 0;
        for(int i = x; i; i -= lowbit(i)){
            res += tr[i];
        }
        return res;
    }
    inline ll sum(int l, int r) { return ask(r)-ask(l-1); }
};*/