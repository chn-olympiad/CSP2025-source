#include <bits/stdc++.h>
using namespace std;
int n,m;
int R,a[400];
int c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m >> R;
    for(int i=2;i<=n*m;i++) cin >> a[i];
    a[1]=R;
    sort(a+1,a+n*m+1,greater<int>());
    int g=lower_bound(a+1,a+n*m+1,R,greater<int>())-a;
    if(g%n!=0) c=g/n+1;
    else c=g/n;
    if(c%2>0){
        if(g%n<1) r=n;
        else r=g%n;
    }
    else{
        if(!(g%n)) r=1;
        else r=n-g%n+1;
    }
    cout << c << " " << r;
    return 0;
}
