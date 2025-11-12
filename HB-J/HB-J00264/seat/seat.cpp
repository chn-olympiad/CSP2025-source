#include<bits/stdc++.h>
using namespace std;
#define mid l+r>>1
const int N=10+5;
int n, m;
int a[N*N];
int finn(int l, int r, int k) {
    if(a[mid]==k) return mid;
    if(a[mid]<k) return finn((mid)+1, r, k);
    return finn(l, (mid)-1, k);
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; ++i) cin>>a[i];
    a[0]=a[1];
    sort(a+1, a+n*m+1);
    int pos;
    pos=n*m-finn(1, n*m, a[0])+1;
    // cout<<pos<<'\n';//
    int x, y;
    x=(pos+n-1)/n;
    if(x&1) {
        y=pos-(x-1)*n;
    }
    else {
        y=x*n+1-pos;
    }
    cout<<x<<" "<<y;
    return 0;
}