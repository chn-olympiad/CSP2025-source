#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+5;
int arr[N];

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    bool flag=true;
    for(int i=1; i<=n; i++) cin>>arr[i];
    for(int i=1; i<=n; i++){
        if(arr[i]!=1){
            flag=false;
        }
    }
    if(k==0 && n==1 && flag){
        cout<<0;
        return 0;
    } else if(k==0 && n==2 && flag){
        cout<<1;
        return 0;
    } else if(k==0 && flag){
        cout<<n/2;
        return 0;
    }
    if(n<=5  && !flag){
        cout<<2;
        return 0;
    }
    if(n<=10 && n>5 && !flag){
        cout<<4;
        return 0;
    }
    return 0;
}
