#include<bits/stdc++.h>
using namespace std;
int a[500001]={};
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    bool f=0;
    for(int i=1;i<=n;i++){
        if(!f)a[i]=(a[i]+a[i-1])%2;
        else f=0;
        if(a[i]==k){
            ans++;
            f=1;
        }
    }
    cout<<ans;
    return 0;
}
