#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int p = 1e9 + 7;
const int maxn = 2e5 + 5;
ull rep_hash[maxn], change_hash[maxn], arr_pow[maxn];
ull now_hash[maxn], target_hash[maxn];
char str1[maxn], str2[maxn];
int n, q;
void get_pow(int n){
    arr_pow[0] = 1;
    for(int i = 1; i <= n; i++){
        arr_pow[i] = arr_pow[i - 1] * p;
    }
}
void get_rep_hash(int pos, char *str){
    int len = strlen(str);
    char temp_hash[maxn];
    for(int i = 0; i < len; i++){
        temp_hash[i] = temp_hash[i - 1] + str[i] * p;
    }
    rep_hash[pos] = temp_hash[len - 1];
}
void get_change_hash(int pos, char *str){
    int len = strlen(str);
    char temp_hash[maxn];
    for(int i = 0; i < len; i++){
        temp_hash[i] = temp_hash[i - 1] + str[i] * p;
    }
    change_hash[pos] = temp_hash[len - 1];
}
int solve(){
    /*int len_now = strlen(str1), len_target = strlen(2);
    for(int i = 0; i < len_now; i++){
        now_hash[i] = now_hash[i - 1] + str[i] * p;

    }
    change_hash[pos] = temp_hash[len - 1];*/
    //yi hou zen me ban, zhi you tian zhi dao
    //AFO incoming
    return 0;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    get_pow(n);
    for(int i = 1; i <= n; i++){
        cin >> str1 >> str2;
        get_rep_hash(i, str1);
        get_change_hash(i, str2);
    }
    for(int i = 1; i <= q; i++){
        cin >> str1 >> str2;
        cout << solve() << '\n';
    }
    return 0;
}
