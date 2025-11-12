#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,o,p;
    cin>>n>>m;
    cin>>o;
    for(int i=0;i<n*m-1;i++){
        cin>>a[i];
    }sort(a,a+n*m-1);
    for(int i=n*m-2;i>=0;i--){
        if(a[i]>o){
            p=i;
            break;
        }
    }
    cout<<(p-1)/n+1<<" ";
    if(((p-1)/n)%2==0){
        if(p%n==0){
            cout<<n;
        }else{
            cout<<p%n;
        }
    }else{
        if(p%n==0){
            cout<<1;
        }else{
            cout<<5-p%n;
        }
    }
    return 0;
}
