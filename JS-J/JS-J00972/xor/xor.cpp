#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000100];
int aans;
bool boo=false;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)boo=true;
    }
    if(k==0 && boo==false){
        cout<<n/2;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            ans++;
        }
        if(a[i-1]==1 && a[i-1]==a[i]){
            aans++;
        }
    }
    //cout<<ans/k;
    if(k==1)cout<<ans;
    else cout<<n-ans+aans;
    //cout<<"gregt";
    return 0;
}
