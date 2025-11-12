#include<bits/stdc++.h>
using namespace std;
int t[105],a[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>a[i];
       t[a[i]]++;
    }
    int pos=0;
    for(int i=100;i>=1;i--){
        if(i==a[1]){
            pos=100-i+1;
            break;
        }
    }
    int x,y;
    if(pos%m!=0){
        x=pos/m+1;
    }else{
        x=pos/m;
    }
    if(x%2==1){
        y=pos%(2*m);
    }else{
        y=m-pos%m+1;
    }
    cout<<x<<" "<<y;
    return 0;
}/*

*/
