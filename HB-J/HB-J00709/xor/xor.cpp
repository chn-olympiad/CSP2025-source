#include<bits/stdc++.h>
using namespace std;
long long a,b,c[500005],o;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
        if(c[i]>o)
            o=c[i];}
    cout<<o;
    return 0;}
