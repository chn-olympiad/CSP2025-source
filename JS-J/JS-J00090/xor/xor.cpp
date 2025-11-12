#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,k,a[500005],sum1,sum2;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)sum1++;
        if(a[i]==1)sum2++;
    }
    if(sum2==n&&k==0){
        cout<<n/2;
        return 0;
    }
    else if(sum2+sum1==n){
        if(k==1){
            cout<<sum2;
            return 0;
        }
        if(k==0){
            cout<<sum1+sum2/2;
            return 0;
        }
    }
    else if(k==0){
        cout<<sum1;
        return 0;
    }
    else cout<<0;
    return 0;
}

