#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long a[maxn],sum[maxn];
long long cnt,n,k;
int main(){

    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    /*
    for(int i=1;i<=n;i++) cout<<sum[i]<<" ";
    cout<<endl;
    **/
    int last=0;
    for(int i=1;i<=n;i++){
        for(int j=last;j<=i-1;j++){
            if((sum[j]^sum[i])==k){
                cnt++;
                last=i;
                //cout<<j+1<<" "<<i<<endl;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
