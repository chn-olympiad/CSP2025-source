#include <bits/stdc++.h>
#define int unsigned long long
#define N 500100
using namespace std;
int a[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt0=0,cnt1=0,cnto=0,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)
            cnt0++;
        if(a[i]==1)
            cnt1++;
        if(a[i]!=0 && a[i]!=1)
            cnto++;
    }
    if(!cnto){
        if(!cnt0){
            if(k==0){
                cout<<n/2;
                return 0;
            }
            if(k==1){
                cout<<n;
                return 0;
            }
            cout<<0;
            return 0;
        }
        if(k==0){
            int sz1=0;
            for(int i=1;i<=n;i++){
                if(a[i]==1)
                    sz1++;
                if(a[i]==0)
                    ans+=sz1/2,ans++;
            }
            cout<<ans;
            return 0;
        }
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1)
                    ans++;
            }
            cout<<ans;
            return 0;
        }
        cout<<0;
        return 0;
    }
    else{
        for(int i=1;i<=n;i++){
            int xorh=0;
            for(int j=i;j<=n;j++){
                xorh^=a[j];
                if(xorh==k){
                    ans++,i=j;
                    break;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
