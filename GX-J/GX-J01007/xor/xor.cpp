#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],pre[500001],pp[500001],sum;
int ff(int r,int l){
    for(;r<=l;r++){
        if(pp[r]>=1){
            return 1;
        }
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=(pre[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(pre[j]-pre[i-1]==k&&ff(i,j)==0){
                sum++;
                for(int o=i;o<=j;o++){
                    pp[o]++;
                }
            }
        }
    }

    cout<<sum;
    return 0;
}
