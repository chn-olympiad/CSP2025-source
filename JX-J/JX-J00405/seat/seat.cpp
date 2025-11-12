#include<bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n,m,a[N],a1,s,c,r;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n * m;i++){
        cin >> a[i];
    }
    a1 = a[1];
    sort(a + 1,a + n * m + 1,cmp);
    for(int i = 1;i <= n * m;i++){
        if(a[i] == a1){
            s = i;
            break;
        }
    }
    if(s % n == 0){
        c = s / n;
    }
    else{
        c = s / n + 1;
    }
    if(c % 2 == 1){
        s -= (c - 1) * n;
        r = s;
    }
    else{
        s -= (c - 1) * n;
        r = n - s + 1;
    }
    cout << c << " " << r;
    return 0;
}
