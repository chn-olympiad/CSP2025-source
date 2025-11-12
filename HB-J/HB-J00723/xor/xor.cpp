#include <bits/stdc++.h>
using namespace std;
int a[600000];
int xxor(int l,int r){
    if(r==l){
        return a[l];
    }
    else if(l+1==r){
        return a[r]^a[l];
    }
    int mid=(l+r)/2;
    return xxor(l,mid)^xxor(mid,r);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int da=-1;
    for(int i=1;i<=n;i++){
        int ans=0;
        int l;
        for(l=i;l<=n;l++){
            for(int j=l;j<=n;j++){
                if(xxor(l,j)==k){
                        l=j+1;
                    ans++;
                }
            }
        }
        da=max(da,ans);
    }
    cout<<da;
    return 0;
}
//HB-J00723 shizouyu 04-03 2025.11.01  ⨌
