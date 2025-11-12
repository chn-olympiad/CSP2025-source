#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long xs[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        xs[i]=xs[i-1]^a[i];
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((xs[j]^xs[i-1])==k){
                //cout<<i<<" "<<j<<" "<<k<<endl;///////////////////////////////////////////////////////////////////////////////////
                i=j;
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
