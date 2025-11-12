#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5000+5;
int sticks[N];
int main(){
    freopen( "polygon.in" , "r" , stdin);
    freopen( "polygon.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> sticks[i];
    sort( sticks + 1 , sticks + 1 + n );
    if(n < 3) cout << 0 <<endl;
    else if(n == 3 && sticks[1] + sticks[2] > sticks[3]) cout << 1 << endl;
    else if(n == 3 && sticks[1] + sticks[2] <= sticks[3])cout << 0 << endl;
    if(n > 3) cout << ((( n - 2 ) + 1) * (n - 2)) / 2 << endl;
    return 0;
}
