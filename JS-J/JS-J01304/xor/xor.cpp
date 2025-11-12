#include <bits/stdc++.h>
using namespace std;
int a[1000007],sum[1000007];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sum[1]=a[1];
    //cerr<<sum[1]<<' ';
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]^a[i];
        //cerr<<sum[i]<<' ';
    }
    //cerr<<endl;
    int late=0;
    for(int i=1;i<=n;i++){
        for(int j=late;j<i;j++){
            if((sum[i]^sum[j])==k){
                late=i;
                //cerr<<i<<' '<<j<<' '<<sum[i]<<' '<<sum[j]<<' '<<(sum[i]^sum[j])<<endl;
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
