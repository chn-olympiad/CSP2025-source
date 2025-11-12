#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],sor,x,y;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])sor++;
    }
    x=sor/n+1;
    if(x%2)y=sor%2+1;
    else y=n-sor%2;
    cout<<x<<" "<<y;
    return 0;
}
