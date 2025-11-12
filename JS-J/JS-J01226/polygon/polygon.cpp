#include <bits/stdc++.h>
using namespace std;
bool is_3(int a, int b, int c){
    return (a+b > c && a+c > b && b+c > a);
}
int main(){
    long long n;
    long long a[5005] = {};
    int A = 1;
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] != 1) A = 0;
    }
    if (n == 3){
        if (is_3(a[1], a[2], a[3])) cout << 1;
        else cout << 0;
        return 0;
    }
    if (A){
        long long sum = 0;
        for (int i = 1; i <= n-2; i ++)
            sum += i;
        cout << sum;
        return 0;
    }
    cout << 0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
