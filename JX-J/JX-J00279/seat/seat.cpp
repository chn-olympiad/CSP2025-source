#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[101],s=0,l=0,k=0,b=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        l=a[1];
    }
    sort(a,a+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(a[i]==l){
            s=n*m-i+1;
            break;
        }
    }
    k=s/n;
    if(s%n==0 and k%2==0){
        cout<<k<<" "<<1;
    }
    else if(k%2==1 and s%n==0){
        cout<<k<<" "<<n;
    }
    else if(k%2==1){
        cout<<k+1<<" "<<n-(s%n)+1;
    }
    else{
        cout<<k+1<<" "<<(s%n);
    }
    return 0;
}
