#include <bits/stdc++.h>
using namespace std;
int n,m,rs,a[110],fs,pm,c,r;
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    rs = n * m;
    for(int i = 1;i <= rs;i++){
        cin >> a[i];
    }
    fs = a[1];
    sort(a + 1,a + rs + 1,cmp);
    for(int i = 1;i <= rs;i++){
        if(a[i] == fs){
            pm = i;
        }
    }
    c = ceil((pm * 1.0) / n);
    if(c % 2 == 0){
        r = n - (pm % n);
        if(r == n) r = 1;
        else if(r != n) r += 1;
    } else {
        r = pm % n;
        if(r == 0) r = n;
    }
    cout << c << ' ' << r;
    return 0;
}
