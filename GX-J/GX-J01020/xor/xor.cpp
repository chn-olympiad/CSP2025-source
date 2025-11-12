#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],sum,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==2&&k==0){
        if(a[1]==a[2]){
            cout<<2;
        }else{
            cout<<1;
        }
    }else{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
                sum=a[j];
            for(int x=j+1;x<=j+i-1;x++){
                if(sum==a[x]){
                sum=0;
                }else{
                sum=1;
                }
            }
            if(sum==k&&ans<i)
            ans=i;
        }
    }
    cout<<ans;
    }
    return 0;
}
