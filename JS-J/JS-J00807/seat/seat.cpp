#include <bits/stdc++.h>
using namespace std;
long long n , m;
long long a1 , a[200];
bool cmp(long long a , long long b){
    return a > b;
}
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for (long long i = 1 ; i <= n * m ; i++)
        cin >> a[i];
    a1 = a[1];
    sort(a + 1 , a + n * m + 1 , cmp);
    for (int i = 1 ; i <= n * m ; i++)
        if (a[i] == a1){
            a1 = i;
            break;
        }
    int i = a1 / n , j;
    if (i % 2 == 1){
        if (a1 == n * i) j = n;
        else j = n - a1 + n * i + 1 , i++;
    }
    else {
        if (a1 == n * i) j = 1;
        else j = a1 - n * i , i++;
    }
    cout << i << " " << j;
    return 0;
}
