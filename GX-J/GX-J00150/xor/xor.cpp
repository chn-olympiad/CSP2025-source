#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,a[100005],b=0,k;
bool flagA=true,flagB=true;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)b++;
        if(a[i]!=1)flagA=false;
        if(a[i]>1)flagB=false;

    }
    if(flagA){
        if(n%2==1){
            cout<<n-1;
        }else{
            cout<<n;
        }
    }else if(flagB){
        if(!k)cout<<b;
        else cout<<n-(!(b%2));
    }
    return 0;
}
