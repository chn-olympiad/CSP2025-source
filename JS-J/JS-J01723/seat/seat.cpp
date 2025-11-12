#include <bits/stdc++.h>
using namespace std;

int m, n, k;       // n 行 m 列 k 名
int a[200];
// 第 (k/m+1) 列

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++) cin>>a[i];
    k=1;
    for(int i=2; i<=n*m; i++) if(a[i]>a[1]) k++;
    if(k%n==0) cout<<k/n<<" ";
    else cout<<k/n+1<<" ";

    if( k%n==0 ){
        if( (k/n) % 2 == 0 ) cout<<1<<endl;
        else cout<<n<<endl;
    }
    else if( (k/n+1) % 2 == 1 ) cout<<k%n<<endl;
    else cout<<n+1-k%n<<endl;

    return 0;
}
