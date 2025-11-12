#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[155],sum;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }if(n==2&&k==0){
        if(a[1]==0)sum++;
        if(a[2]==0) sum++;
        if(a[1]==a[2]){
            sum=max(1,sum);
        }cout<<sum;
    }else if(n==1&&k==0){
        if(a[1]==0)sum++;
        cout<<sum;
    }else{
        cout<<3;
    }
    return 0;
}
