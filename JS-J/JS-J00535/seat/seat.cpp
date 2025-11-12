#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],pos=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin >> a[i];
    for(int i=2;i<=n*m;i++){
        if(a[1]<a[i]){
            pos++;
        }
    }
    int y=ceil(double(pos)/double(n)),x=(pos-1)%n+1;
    if((y&1)^1) x=(n+1)-x;
    cout << y << ' ' << x;
    return 0;
}
