#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
    int x=0,ans=0;
    if(k==1){
        for(int i=1;i<=n;i++){
            if(a[i]==1)ans++;
        }
    }
    else if(k==0){
        for(int i=1;i<=n;i++){
            if(a[i]==0)ans++;
            else if(a[i]==a[i-1]&&a[i-1]>=1&&i>1){ans++;a[i]=0;a[i-1]=0;}
    }
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==k)ans++;
        }
    }
    cout<<ans;
    return 0;
}
