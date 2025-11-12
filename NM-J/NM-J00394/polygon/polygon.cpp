#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, a[N], s, ans, m;

bool check (int sum, int max_){
    if (sum > max_*2) return true;
    else return false;
}



int main (){
    freopen ("polygon.in", "r", stdin);
    freopen ("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1;i <= n; i++){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    m = a[n];
    for (int i = 1; i <=n; i++){
        s += a[i];
    }
    if (check (s, m)) ans++;
    if (n == 3){
        cout << ans;
        return 0;
    }
    if (n == 4){
        if (check (s - a[1], m)) ans++;
        if (check (s - a[2], m)) ans++;
        if (check (s - a[3], m)) ans++;
        if (check (s - a[4], a[3])) ans++;
    }
    if (n == 5){
        if (check (s - a[2] - a[3], m)) ans+=3;
        if (check (s-a[3]-a[1],m))ans+=2;
        if(check(s-a[1]-a[2],m))ans++;
        if(check(s-a[1],m))ans++;
        if(check(s-a[5]-a[3],a[4]))ans+=2;
        if(check(s-a[5]-a[1],a[4]))ans++;
        if(check(s-a[5]-a[4],a[3]))ans++;
        if(check(s-a[4],m))ans++;
        if(check(s-a[3],m))ans++;
        if(check(s-a[2],m))ans++;
        if(check(s-a[1],m))ans++;
        if(check(s-a[5],a[4]))ans++;
    }
    if(n == 6){
        for(int i=1;i<=n-1;i++){
            if(check(s-a[i],m))ans++;
        }
        for(int i=1;i<=n-2;i++){
            if(check(s-a[n-1]-a[i],m))ans++;
        }
        for(int i=1;i<=n-3;i++){
            if(check(s-a[n-1]-a[n-2]-a[i],m))ans++;
        }
        if(check(s-a[3]-a[4]-a[5],m))ans++;

    }

    return 0;
}
