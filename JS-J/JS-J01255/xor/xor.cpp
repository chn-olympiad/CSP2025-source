#include<bits/stdc++.h>
using namespace std;
long long n,k,js1=0,js2=0,a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)js1=0;
        if(a[i]==0)js2=0;
    }
    if(js1==n){
        cout<<n;
        return 0;
    }
    return 0;
}
