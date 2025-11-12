#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005];
int cnt = 1;
int w, w2;
int ans1, ans2;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[cnt++];
        }
    }
    w = a[1];
    //cout << w << endl;
    sort(a + 1, a + cnt + 1, cmp);
    /*for(int i = 1; i < cnt; i++){
        cout << a[i] << endl;
    }*/
    for(int i = 1; i < cnt; i++){
        if(a[i] == w){
            w2 = i;
            break;
        }
    }
    //cout << w2 << endl;
    if(w2 % n == 0){
        ans2 = w2 / n;
        if(ans2 % 2 == 0){
            ans1 = 1;
        }
        else{
            ans1 = n;
        }
        cout << ans2 << ' ' << ans1;
        return 0;
    }
    else{
       ans2 = w2 / n + 1;
       if(ans2 % 2 == 0){
            int le = n - (w2 % n);
            ans1 =  le + 1;
       }
       else{
            ans1 = w2 % n;
       }
       cout << ans2 << ' ' << ans1;
    }

    return 0;
}
