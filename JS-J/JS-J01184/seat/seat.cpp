#include <bits/stdc++.h>
using namespace std;
int n,m,a[105] = {},r_score,c = 0,r = 1;
bool cmp(int a,int b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 0;i < n * m;i++){
        cin >> a[i];
    }
    r_score = a[0];
    sort(a,a + n * m,cmp);
    for (int i = 0;i < n * m;i++){
        if (r < n && c % 2){
            r++;
        }
        else if (r > 1 && !(c % 2)){
            r--;
        }
        else{
            c++;
        }
        if (a[i] == r_score){
            cout << c << ' ' << r;
            return 0;
        }
    }
    return 0;
}
