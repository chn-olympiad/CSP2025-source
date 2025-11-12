#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],sum,b[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k==0){
        cout<<1;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        b[i]=a[i]|sum;
        sum=a[i];
    }
    sum=0;
    for(int i=0;i<k;i++){
        sum=max(b[i],sum);
    }
    cout<<sum-1;
    return 0;
}
