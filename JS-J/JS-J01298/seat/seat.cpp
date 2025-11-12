#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long a[10005],k=1,n,m,x,y;
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++){
       cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1);
    for(long long i=1;i<=n*m;i++){
        if(a[i]==k){
            k=n*m-i+1;
        }
    }

    if(k%n==0){
        y=n;
        x=k/n;
    }
    else{
        x=k/n+1;
        y=k%n;
    }

    if(x%2==0){
        y=n-y+1;
    }
    cout<<x<<" "<<y;
    return 0;
}
