#include<bits/stdc++.h>
using namespace std;
int a[1000005],n,k,ans,sum;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            sum=-1;
        }
        else{
            if(sum==-1){
                sum=a[i];
            }
            else{
                sum^=a[i];
            }
            if(sum==k){
                ans++;
                sum=-1;
            }
        }
    }
    cout<<ans;
    return 0;
}
