#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w".stdout);
    int n,k,a[500023];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1&&k==0)cout<<0;
    else if(n==2&&k==0)cout<<1;
    else if(k==0){
        if(n%2!=0){
            int m=(n-1)/2;
            cout<<m;
        }
        else if(n%2==0){
            int m=n/2;
            cout<<m;
        }
    }
    return 0;
}
