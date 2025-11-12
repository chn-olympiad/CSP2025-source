#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],sum[500005],idx=0,cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=idx+1;j<=i;j++){
            if((sum[i]^sum[j-1])==m){
                cnt++;
                idx=i;
                i++;
                break;
            }
        }
    }
    cout<<cnt;
}
