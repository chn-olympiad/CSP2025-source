#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,k,cnt1,cnt0,cntk;
int a[N];
int ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt0++;
        if(a[i]==k) cntk++;
    }
    if(k==0){
        if(cnt1==n){
            ans=n/2;
        }
    }
    if(k==1){
        if(cnt1+cnt0==n){
            ans=cnt1;
            for(int i=1;i<n;i++){
                if(a[i]==0){
                    if(a[i+1]==0){
                        ans++;
                    }
                    i++;
                }
            }
        }
    }
    if(k==0&&cnt1+cnt0==n){
        ans=cnt0;
        for(int i=1;i<n;i++){
            if(a[i]==1){
                if(a[i+1]==1){
                    ans++;
                }
                i++;
            }
        }
    }
    if(n==1){
        if(a[n]==k) ans=1;
        else ans=0;
    }
    if(n==2){
        if(cntk>0) ans=cntk;
        else{
            if((a[1]^a[2])==k) ans=1;
            else ans=0;
        }
    }
    cout<<ans;
    return 0;
}
