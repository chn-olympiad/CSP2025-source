#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r,a,b,cnt=1;
    cin >> n >> m;
    cin >> a;
    for(int i=1;i<n*m;i++){
        cin >> b;
        if(b>a)cnt++;
    }
    c=(cnt-1)/n+1;
    r=min(cnt%(2*n),2*n+1-cnt%(2*n));
    cout << c << " " << r;
    return 0;
}
