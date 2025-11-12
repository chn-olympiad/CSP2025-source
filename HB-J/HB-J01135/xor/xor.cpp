#include "bits/stdc++.h"
using namespace std;

//ex 20-30
//486 I Love U

//AFO

long long ans=0,cnt=0;
long long arr[500005]={};
long long n,k,maxn=-1;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        maxn=max(arr[i],maxn);
    }
    if(k>1){
        int pro=k^maxn;
        cout<<pro;
    }else if(k==0){
        for(int i=1;i<=n;i++){
            if(arr[i]==0) ans++;
            else if(arr[i]==1) cnt++;
        }
        ans+=cnt/2;
        cout<<ans<<endl;
    }else if(k==1){
        for(int i=1;i<=n;i++){
            if(arr[i]==1) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
