#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[100001]={},c,r,a1,s;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    a1=a[1];
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=n*m;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
//   for(int i=1;i<=n*m;i++){
//     if(a[i]==a1){
//       s=i;
//      }
//     }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
            if(a1==a[i]){
                r=j%4;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(a1==a[i]){
                r=4-j%4;
                break;
            }
        }
        c=j/4+1;
    }
    cout<<c<<" "<<r;
    return 0;
}
/*
r=s%4;
c=s/4;
r=4-s%4;
c=s/4;
*/
