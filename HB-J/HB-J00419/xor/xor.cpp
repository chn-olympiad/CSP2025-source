#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
bool bj=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) bj=0;
    }
    if(bj){
        cout<<n/2;
        return 0;
    }
    if(k==1){
        int cnt=0;
        for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
        cout<<cnt;
    }else if(k==0){
        int cnt1=0,cnt0=0;
        for(int i=1;i<=n;i++) if(a[i]==1) cnt1++;
                              else if(a[i]==0) cnt0++;
        cout<<cnt0+cnt1/2;
    }
    return 0;
}
