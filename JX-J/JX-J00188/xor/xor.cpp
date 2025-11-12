#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans,l,r,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    l=1;
    r=1;
    while(l<=r){
        sum=l;
        for(int i=l+1;i<=r;i++){
            sum=sum|a[i];
        }
        if(sum==k)  ans++;
        if(sum<k){
            r++;
        }
        if(sum>k){
            l++;
        }
    }
    cout<<ans;
    return 0;
}
