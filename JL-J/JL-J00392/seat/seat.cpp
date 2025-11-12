#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,z=1,b;
    int r=0,c=0;
    cin>>n>>m;
    int a[n*m];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    b=a[0];
    sort(a,a+n*m);
    for(int i=n*m-1;i>=0;i--){
        r+=z;
        if(r==n){
            c++;
            z=-1;
        }else if(r==0){
            c++;
            z=1;
        }
        if(a[i]==b){
            cout<<c<<" "<<r<<endl;
        }
    }
    return 0;
}
