#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,c,r;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i){
        cin>>a[i];
        if(a[i]>=a[1])++x;
    }
    c=(x+n-1)/n;
    if(c%2)r=(x+n-1)%n+1;
    else r=n-(x+n-1)%n;
    cout<<c<<" "<<r;
    return 0;
}
