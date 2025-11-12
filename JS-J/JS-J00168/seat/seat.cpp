#include <bits/stdc++.h>
using namespace std;
int a[1001],k;
bool cmp(int c,int d){
    return c > d;
}
bool check(int cnt){
    if(a[cnt] == k) return true;
    else return false;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cin >> k;
    a[1] = k;
    for(int i = 2;i <= n * m;i ++) cin >> a[i];
    sort(a+1,a+n*m+1,cmp);
    int x =0,y = 1,cnt = 0;
    while(x * y <= n * m && x <= n && y <= m && cnt <= n * m){
      //  cout <<y << ' ' << x << " " << a[cnt] << '\n';
        while(x < n){
            x++;
            if(check(++cnt)){
                cout << y << " " << x << '\n';
                return 0;
            }
          //  cout << y << " " << x << " " << a[cnt] << '\n';
        }
      //  cout << a[cnt] << '\n';
        y ++;
        if(check(++cnt)){
             cout << y << " " << x << '\n';
             return 0;
        }
       // cout << y << " " << x << " " << a[cnt] << '\n';
        x --;
        while(x >= 1){
            if(check(++cnt)){
                cout << y << " " << x << '\n';
                return 0;
            }
          //  cout << y << " " << x << " " << a[cnt] << '\n';
            x--;
        }
        x++, y ++;
        if(check(++cnt)){
             cout << y << " " << x << '\n';
             return 0;
        }
    }
    return 0;
}
/*
5 4
88 100 99 98 97 96 95 94 93 92 91 90 89 87 86 85 84 83 82 81

4 4
94 100 99 98 97 96 95 88 93 92 91 90 89 87 86 85
*/