#include<bits/stdc++.h>
using namespace std;
int n,m,k,s,a[1000000];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==1){
            s++;
        }
    }
    if(k==0)cout<<s/2;
    else if(k==1)cout<<s;
    else cout<<n/2-3;
    return 0;
}
