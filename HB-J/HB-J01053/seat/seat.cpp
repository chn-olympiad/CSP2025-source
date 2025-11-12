#include<bits/stdc++.h>
using namespace std;
int n, m, q, r, a[111], h, z, c, s;
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n == 1 && m == 1){
        cin>>q;
        cout<<1<<" "<<1;
        return 0;
    }
    if(n == 1){
        for(int i = 1;i <= m;i++){
            cin>>a[i];
        }
        r = a[1];
        sort(a + 1, a + 1 + m, cmp);
        for(int i = 1;i <= m;i++){
            if(a[i] == r) cout<<i<<" "<<1;
        }
        return 0;
    }
    if(m == 1){
        for(int i = 1;i <= n;i++){
            cin>>a[i];
        }
        r = a[1];
        sort(a + 1, a + 1 + n, cmp);
        for(int i = 1;i <= n;i++){
            if(a[i] == r) cout<<1<<" "<<i;
        }
        return 0;
    }
    if(n == 2 && m == 2){
        cin>>a[1]>>a[2]>>a[3]>>a[4];
        r = a[1];
        sort(a+1,a+5);
        if(a[4] == r){
            cout<<1<<" "<<1;
        }
        if(a[3] == r){
            cout<<1<<" "<<2;
        }
        if(a[2] == r){
            cout<<2<<" "<<2;
        }
        if(a[1] == r){
            cout<<2<<" "<<1;
        }
        return 0;
    }
    q = n * m;
    for(int i = 1;i <= q;i++){
        cin>>a[i];
    }
    r = a[1];
    sort(a + 1, a + 1 + q, cmp);
    for(int i = 1;i <= q;i++){
        if(a[i] == r) h = i;
    }
    if(h % n != 0)
        c = h / n + 1;
    else{
        c = h / n;
    }
    if(c % 2 == 1){
        if(h % n == 0){
            s = n;
        }
        else{
            s = h % n;
        }
    }
    if(c % 2 == 0){
        s = n - (h % n) + 1;
    }
    cout<<c<<" "<<s;
    return 0;
}
