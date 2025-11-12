#include<bits/stdc++.h>
using namespace std;
bool tmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[105],k;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+1+n*m,tmp);
    for(int i=n*m;i>=1;i--){
        if(a[i]==k){
            if(((i-1)/n+1)%2!=0){
                cout<<(i+n-1)/m<<" "<<(i-1)%m+1;
                break;
            }
            if(((i-1)/n+1)%2==0){
                cout<<(i+n-1)/m<<" "<<(i+1)/n;
                break;
            }
        }
    }
    return 0;
}
