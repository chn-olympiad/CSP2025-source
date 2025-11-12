#include<bits/stdc++.h>
using namespace std;

int n,k;

int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    int c=0;
    for(int i=0;i<n;++i){
        int item;
        cin>>item;
        c+=item;
    }
    if(k)
        cout<<c;
    else
        cout<<n/2;

    return 0;
}
