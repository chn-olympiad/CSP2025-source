#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c;
int a[110];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m >> c;
    a[1] = c;
    for(int i = 2;i <= n * m;i++){
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n * m);
    int l = 1,r = n * m;
    while(l < r){
        int mid = l + r >> 1;
        if(a[mid] < c){
            l = mid;
        }else if(a[mid] > c){
            r = mid;
        }else{
            l = mid;
            r = mid;
        }
    }
    l = n * m - l + 1;
    int y = (l + n - 1) / n,x = n;
    if(y % 2 == 1){
        x = l % n;
        if(x == 0) x = n;
    }else{
        x -= l % n - 1;
    }
    cout << y << ' ' << x << '\n';
    return 0;
}