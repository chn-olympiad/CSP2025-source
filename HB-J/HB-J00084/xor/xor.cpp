#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor","r",stdin);
    freopen("xor","w",stdout);
    int n,k,a[10000];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans,s;
    for(int i=1;i<=k;i++){
        ans=a[i]^a[i+1];
    }
    for(int i=k;i<k+1;i++){
        s=a[i]^a[i+1];
    }
    if(ans>s){
        cout<<ans;
    }else{
        cout<<s;
    }
    return 0;
}
