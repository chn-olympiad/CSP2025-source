#include<bits/stdc++.h>
using namespace std;
int a[33][33],m,n,c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(nullptr);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    if(n==1 && m==1){
        cout<<a[1][1];
        return 0;
    }
    if(max(a[1],max(a[2],max(a[3],a[4])))==a[1]) cout<<1<<" "<<1;
    if(min(a[1],max(a[2],max(a[3],a[4])))==a[1]) cout<<1<<" "<<2;
    else cout<<2<<" "<<1;
    return 0;
}
