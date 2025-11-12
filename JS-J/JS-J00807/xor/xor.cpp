#include <bits/stdc++.h>
using namespace std;
long long n , m , sum , num;
bool B;
int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> m;
    for (long long i = 1 ; i <= n ; i++){
        long long x;
        cin >> x;
        if (!B) sum = x , B = true;
        else sum = sum ^ x;
        if (sum == m) num++ , B = false;
    }
    cout << num;
    return 0;
}
