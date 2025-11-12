#include<bits/bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int c,r,a[100]x,y,i,j,k=1,su;
    cin>>c>>r;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    for(i=1;i<=c*l;i++){
        cin>>a[i];
    }
    su=a[1];
    for(i=1;i<=c*l;i++){
        if(a[i]>a[i-1){
            k=a[i];
            a[i]=a[i-1];
            a[i-1]=k;
        }
    }
    for(i=1;i<=c*l;i++){
        if(su==a[i]){
            if(i>l){
                cout<<i/l<<i%l;
            }
        }
    }
}
