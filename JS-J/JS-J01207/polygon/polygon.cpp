#include<bits/stdc++.h>
using namespace std;
int a[5005],s,m,n;
long long cnt;
void f(int d,int s,int m,int z){
    cnt %= 998244353;
    if(d > n){
        return;
    }
    s += a[d];
    m = max(m,a[d]);
    for(int i = 1;i <= n;i++){
        f(d + i,s,m,z + 1);
    }
    if(z <= 2){
        return;
    }
    if(s > m * 2){
        cnt++;
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n <= 2){
        cout << 0;
        return 0;
    }
    f(0,0,0,0);
    cout << cnt;
    return 0;
}
