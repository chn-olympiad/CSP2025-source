#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],n,k,ans,r=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
            int f=1;
        for(int j=r;j<=i&&f;j++){
            if((b[i]^b[j-1])==k){
                ans++;
                r=i+1;
                f=0;
            }
        }

    }
    cout<<ans;
    return 0;
}
