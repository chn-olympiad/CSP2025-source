#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int cnt0=0,cnt1=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt0++;
    }
    if(k==0){
        if(cnt0==0){
            cout<<n/2;
        }
        else {
            int ans=0;
            for(int i=0;i<=n;){
                if(a[i]==0){
                    ans++;
                    i++;
                }
                else if(a[i]==1){
                    if(a[i+1]==1){
                        ans++;
                        i+=2;
                    }
                    else i++;
                }
            }
            cout<<ans;
        }
    }
    else if(k==1){
        int ans=0;
        for(int i=1;i<=n;){
            if(a[i]==1){
                if(i+1<=n&&a[i+1]==0) {
                    ans++;
                    i+=2;
                }
                else if(a[i+1]==1&&a[i+2]==1){
                    ans++;
                    i+=3;
                }
                else i++;
            }
            else if(a[i]==0){
                if(a[i+1]==1) {
                    ans++;
                    i+=2;
                }
                else i++;
            }
        }
        cout<<ans;
    }
    //30
    return 0;
}
