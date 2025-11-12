#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
bool flg[510];
char s[510];
///int f[100010];
int a[510];
int b[510];
long long ans;
int n , m;
bool is_A = true;
/**
int dfs(int t , int cnt){
    if(f[t] != -1) return f[t];
    f[t] = 0;
    for(int i = 1 ; i <= n ; i++){
        if(((1 << (i - 1)) | t) != t && a[i] >= b[i]){
            f[t] += dfs(t | (1 << (i - 1)) , cnt + 1);
            f[t] %= mod;
        }
    }
    return f[t];
}
int bit_count(long long t){
    long long x = 1;
    int cnt = 0;
    while(x <= t){
        if((x | t) != t) cnt++;
        x <<= 1;
    }
    return cnt;
}
**/
bool check(){
    int cnt = 0;
    int t = 0;
    for(int i = 1 ; i <= n ; i++){
        if(a[b[i]] > t && flg[b[i]]) cnt++;
        else t++;
        if(cnt >= m) return true;
    }
    return false;
}
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
    scanf("%d%d" , &n , &m);
    scanf("%s" , s + 1);
    for(int i = 1 ; i <= n ; i++){
        flg[i] = s[i] - '0';
        is_A &= flg[i];
        scanf("%d" , &a[i]);
    }
    if(is_A){
        ans = 1;
        for(int i = 1 ; i <= n ; i++){
            ans *= i;
            ans %= mod;
        }
        printf("%lld" , ans);
        return 0;
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; i++) b[i] = i;
    do{
        if(check()){
            ans++;
            ans %= mod;
        }
    }while(next_permutation(b + 1 , b + n + 1));
    printf("%lld" , ans);
    return 0;
}
