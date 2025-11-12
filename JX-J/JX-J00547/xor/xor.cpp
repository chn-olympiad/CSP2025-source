#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
int f(int l,int r){
    if(l==r)
        return a[l];
    return a[l]^f(l+1,r);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(f(i,j)==k){
                cnt++;
                i=j+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
