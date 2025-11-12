#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],sum[500005],cnt;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1] xor a[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((sum[i] xor sum[j-1])==k&&i<=j){
                cnt++;
                i=j+1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
