#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,cnt=1,x,c,r;
    cin >> n >> m >> a;
    for(int i=1;i<n*m;i++){
        cin >> x;
        if(x>a){
            ++cnt;
        }
    }
    c=ceil(cnt*1.0/n);
    r=(cnt-1)%n+1;
    if(c%2==0){
        r=n-r+1;
    }
    cout << c << ' ' << r;
    return 0;
}
