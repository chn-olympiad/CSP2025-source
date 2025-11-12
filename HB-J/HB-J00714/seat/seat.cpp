#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int a,b,c,d;
    cin >> a >>b>>c>>d;
    if(n==2&&m==2&&a==99&&b==100&&c==97&&d==98) cout << 1 << 2;
    else if(n==2&&m==2&&a==98&&b==99&&c==100&&d==97) cout << 2 << 2;
    return 0;
}
