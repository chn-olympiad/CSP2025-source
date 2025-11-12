#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c=1,r=1,x=0;
    cin>>n>>m;
    x=n*m;
    int a[x];
    for(int i=1;i<=x;i++){
        cin>>a[i];
    }
    for(int j=1;j<=x;j++){
        if(a[j]>a[1]){
            r++;
        }
        if(r>n){
            c++;
            r=1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}

