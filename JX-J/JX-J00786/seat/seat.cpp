#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,a[101]={},a1=0,zw=0,c=0/*列*/,r=0/*行*/;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a1;
    for(int i=1;i<=n*m-1;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n*m-1;i++){
        for(int l=1;l<=n*m-1;l++){
            if(a[l]<a[l+1]){
                swap(a[l],a[l+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++){
        if(a1>a[i]){
            zw=i;
            break;
        }
    }
    if(zw%n==0){
        if(zw/n%2==0){
            cout<<zw/n<<" "<<1;
        }
        else{
            cout<<zw/n<<" "<<n;
        }
    }
    else if(zw/n%2==0){
        cout<<zw/n+1<<" "<<zw%n;
    }
    else{
        cout<<zw/n+1<<" "<<n-zw%n+1;
    }
    return 0;
}
