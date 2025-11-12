#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,k1=0,k0=0,ans=0;
int a[N];
bool okone=1,oko=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) k0++;
        if(a[i]!=1) okone=0;
    }
    if(okone){
        cout<<n;return 0;
    }
    if(k==0){
        int sum=0,w=0,p=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]!=p) sum+=w/2,p=a[i],w=0;
            else w++;
        }
        cout<<sum+k0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==255){
            if(a[i-1]==255-k||a[i+1]==255-k){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
