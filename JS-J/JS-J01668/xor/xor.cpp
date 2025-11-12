#ifndef XOR_CPP_INCLUDED
#define XOR_CPP_INCLUDED



#endif // XOR_CPP_INCLUDED

#include <bits/stdc++.h>
using namespace std;
const long long o=6e5;
long long n,k,a[o];
long long f,b[5];
long long x,l;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
        cin>>n>>k;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0){
            b[0]++;
        }
        else if(a[i]==1){
            b[1]++;
        }
        else{
            f=1;
        }
    }
    if(f==0){
        if(k==0){
            cout<<b[0];
        }
        else if(k==1){
            cout<<b[0]/2+b[1];
        }
        else{
            cout<<0;
        }
    }
    else{
        for(long long i=1;i<=n;i++){
            if(a[i]==k){
                l++;
                continue;
            }
            x=a[i];
            for(long long j=i+1;j<=n;j++){
                if(a[j]==k){
                    break;
                }
                x^=a[j];
                if(x==k){
                    l++;
                    i=j+1;
                }
            }
        }
        cout<<l;
    }
    return 0;
}
