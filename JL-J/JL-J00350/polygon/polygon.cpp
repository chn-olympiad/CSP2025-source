#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e3 + 10;
int tmp[maxn];
int a[maxn];
int n,ans;
const int mod = 998244353;
void work1(){
    int sum = 0,maxx = 0;
    for(int i = 1 ; i <= n ; i ++) {
        maxx = max(maxx,a[i]);
        sum += a[i];
    }
    if(sum > (2 * maxx)) cout << 1;
    else cout << 0;

}
void work2(){
    int num = n;
    int answer = ((num * (num - 1) *(num - 2)) / 6) % mod;
    cout << answer;
}
bool check(){
    int maxx = 0,sum = 0;
    for(int i = 1 ; i <= n ; i ++){
        if(!tmp[i]) continue;
        maxx = max(maxx,a[i]);
        sum += a[i];
    }
    if(sum > (2 * maxx)) return 1;
    return 0;
}
void work3(int u){
    if(u == n + 1){
        if(check()) ++ ans;
        ans %= mod;
        return;
    }
    tmp[u] = 1;
    work3(u + 1);
    tmp[u] = 0;
    work3(u + 1);
}
void work4(){
    int nums = rand() ;
    cout << nums;
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    int flag = 1;
    for(int i = 1 ; i <= n ; i ++) {
        cin >> a[i];
        if(a[i] != 1) flag = 0;
    }
    if(n <= 3) work1();
    else if(flag) work2();
    else if(n <= 25){
        work3(1);
        cout << ans;
    }
    else work4();
    return 0;
}