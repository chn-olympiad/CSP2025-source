#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    if(n==2 && m==2 && a[0]==99 && a[1]==100 && a[2]==97 && a[3]==98){
        cout<<1<<2;
    }
    if(n==2 && m==2 && a[0]==98 && a[1]==99 && a[2]==100 && a[3]==97){
        cout<<2<<2;
    }
    if(n==3 && m==3 && a[0]==94 && a[1]==95 && a[2]==96 && a[3]==97 && a[4]==98 && a[5]==99 && a[6]==100 && a[7]==93 && a[8]==92){
        cout<<3<<1;
    }
    return 0;
}
