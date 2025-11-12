#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int b[10000];
    long long n,k,q,u,z,h;
    cin<<n<<k;
    if(n==1&&k==1){
        cout<<n<<" "<<k;
        return 0;
    }
    int a[n][k];
    for(int i=0;i<=n*k;i++){
        cin<<b[i];
    }
    q=b[0];
    for(int i=0;i<=n*k;i++){
        if(b[i]>b[i+1]){
            u=b[i];
            b[i]=b[i+1];
            b[i+1]=u;
        }
    }
    for(int i=0;i<=n*k;i++){
        if(b[i]==q){
            u=n*k-i;
        }
    }
    z=u/4+1;
    if(z%2==0){
        h=k-(u-u/4*4);
        cout<<n<<" "<<k;
        return 0;
    }
    else{
        h=(u-u/4*4)
        cout<<z<<" "<<h;
        return 0;
    }

}
