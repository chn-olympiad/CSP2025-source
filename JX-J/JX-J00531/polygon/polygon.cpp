#include<bits/stdc++.h>
using namespace std;
long long n,j,mx;
long long a[5005];
long long d,k;

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<0;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==3){
        if(a[1]+a[2]>a[3]*2){
                k++;
        }
        if(a[3]+a[2]>a[1]*2){
               k++;
        }
        if(a[1]+a[3]>a[2]*2){
                k++;
        }
        cout<<k;
    }

    return 0;
}
