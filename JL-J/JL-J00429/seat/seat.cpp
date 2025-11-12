#include <bits/stdc++.h>
using namespace std;
struct node {
    int k;
    int q;
}a[1005];
bool cmp(node x,node y) {
    return x.k>y.k;
}
int n,m,i,q;
int main () {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (i=1;i<=n*m;i++) cin >> a[i].k,a[i].q=i;
    sort(a+1,a+n*m+1,cmp);
    i=1;
    while (a[i].q!=1) i++;
    if (i%m==0) q=i/m,cout << q << ' ';
    else q=i/m+1,cout << q << ' ';
    if (i%m==0 && q%2==0) cout << 1;
    else if (i%m==0 && q%2==1) cout << n;
    else if (q%2==0) cout << n-i%(m+1);
    else cout << i-i/m*m;
    return 0;
}
