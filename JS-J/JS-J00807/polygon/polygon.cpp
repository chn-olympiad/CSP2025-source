#include <bits/stdc++.h>
using namespace std;
long long n , a[5001] , Max;
int dfs(long long sum , long long i , long long num){
    int x = 0;
    while (a[i] == 0) i++;
    for (int j = 0 ; j <= a[i] ; j++){
        if (j != 0 && num + j >= 3 && sum + j * i > i * 2) x++;
        if (i + 1 <= Max) x += dfs(sum + i * j , i + 1 , num + j);
    }
    return;
}
int main(){
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    for (long long i = 1 ; i <= n ; i++){
        long long x;
        cin >> x;
        a[x]++;
        Max = max(Max , x);
    }
    cout << dfs(0 , 1 , 0);
    return 0;
}
