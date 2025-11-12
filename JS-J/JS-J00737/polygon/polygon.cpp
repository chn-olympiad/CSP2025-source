#include <bits/stdc++.h>
using namespace std;
int n,k,ans = 0;
int a[5011];
int b[5011];
bool check(int dep){
    for(int i = dep - 1;i >= 1;i--){
        if(b[dep] <= b[i]) return 0;
    }
    return 1;
}
void print(){
    long long sum = 0;
    for(int i = 1;i <= k;i++){
        sum += a[b[i]];
    }
    if(sum > a[b[k]] * 2) ans++;
    return;
}
void work(int dep){
    if(dep == k + 1){
        print();
        return;
    }
    for(int i = 1;i <= n;i++){
        b[dep] = i;
        if(check(dep)) work(dep + 1);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 3;i <= n;i++){
        k = i;
        work(1);
    }
    cout << ans;
    return 0;
}
