#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],r,c,k;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    k=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            k=n*m-i+1;
            break;
        }
    }
    c=(k-1)/n+1,r=(k-1)%n+1;
    if(c%2==0) r=n-r+1;
    cout<<c<<" "<<r;
    return 0;
}
