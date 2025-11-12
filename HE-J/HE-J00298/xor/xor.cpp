#include<bits/stdc++.h>
using namespace std;
int k,n,s=0,ans=0;
int a[1000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];}
    for(int i=1;i<=n;i++){
        s+=s | a[i];
        if(s==k){
            s=0;ans++;
        }
        if(a[i]==k){
            s=0;ans++;
        }
    }
    cout<<ans;
    return 0;
}
