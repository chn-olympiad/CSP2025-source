#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,l=0,z,ans=0;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    z=a[l];
    for(int j=l+1;j<n;j++){
        z=z^a[j];
        if(z==k){
            ans++;
            l=j;
        }
    }
    cout<<ans<<endl;
    return 0;
}
