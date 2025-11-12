#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 110;
int a[N], n, m;
bool cmp(int a, int b){return a > b;}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n*m; ++i) cin >> a[i];
    int ms = a[1];
    sort(a+1, a+n*m+1, cmp);
    int rnk = -1;
    for(int i = 1; i <= n*m; ++i)
        if(a[i] == ms) rnk = i;
    int c = rnk/n, r;
    if(rnk%n != 0) c++;
    int jo = c%2;
    if(jo == 1) r = rnk%n;
    else r = n-(rnk%n)+1;
    if(rnk%n == 0){
        if(jo == 1) r = n;
        else r = 1;
    }
    cout << c << ' ' << r;
    return 0;
}
