#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001];
long long ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int tot=a[l];
            for(int i=l+1;i<=r;i++){
                tot=a[i]^tot;
            }
            if(tot==k){
                ans++;
            }
        }
    }
    cout<<ans;
}
