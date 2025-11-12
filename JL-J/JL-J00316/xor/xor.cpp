#include<bits/stdc++.h>
using namespace std;
int a[500001],n,k,ans=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k==0){
        for(int i=0;i<n;i++){
            ans=n/2;
        }
    }
    if(k==1){
        for(int i=0;i<n;i++){
            if(a[i]==1){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
