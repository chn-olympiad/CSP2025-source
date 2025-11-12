#include<bits/stdc++.h>
using namespace std;
int arr[100001],sum=0,sum1=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    int l=1,r,r2;
    sum=arr[1];
    for(int i=2;i<=n;i++){
        sum^=arr[i];
        if(sum==k){
            r=i;
            break;
        }
    }
    for(int i=l+1;i<=n;i++){
        sum1^=arr[i];
        if(sum1==k){
            r2=i;
            break;
        }
    }
    cout<<max(r-l+1,r2-l);
    return 0;
}
