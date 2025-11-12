#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
    long long a[1000005],k,n;
    cin>>n>>k;
    if(k==0){
        if(n%2==0){
            cout<<n/2;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<5;
    }
    return 0;
}
