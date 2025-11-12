#include<bits/stdc++.h>
int a[10001];
int b[11][11];//
using namespace std;
bool cmp(const int& x,const int& y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin >> n >> m;
    for(int i = 1;i <= n*m;++i){
        cin >> a[i];
    }
    r = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1;i <= n*m;++i){
        if(a[i] == r){
            int l = (i-1)/n+1;
            cout << l << " " << (l&1?(i-1)%n+1:n-(i-1)%n);
        }
    }
    return 0;
}
