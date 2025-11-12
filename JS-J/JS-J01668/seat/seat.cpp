#ifndef SEAT_CPP_INCLUDED
#define SEAT_CPP_INCLUDED



#endif // SEAT_CPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int n,m;
int l,f;
int x=1,y=1;
int main(){
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdout);
    cin>>n>>m;
    l=n*m;
    for(int i=1;i<=l;i++){
        cin>>a[i];
    }
    f=a[1];
    sort(a+1,a+1+l);
    for(int i=l;i>=1;i--){
        b[y][x]=a[i];
        if(a[i]==f){
            cout<<x<<" "<<y;
            break;
        }
        if(x%2==1){
            if(y==n){
                x++;
            }
            else{
                y++;
            }
        }
        else{
            if(y==1){
                x++;
            }
            else{
                y--;
            }
        }
    }
    return 0;
}
