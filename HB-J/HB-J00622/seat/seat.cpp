#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10000];
int main() {
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=1; i<=n*m; i++) {
        cin>>a[i];
    }
    cout<<m<<" "<<n;
    return 0;
}
