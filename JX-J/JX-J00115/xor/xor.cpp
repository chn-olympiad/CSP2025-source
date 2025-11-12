#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //cout<<a[1];
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]^a[i];
        //cout<<a[i];
    }
    //cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if((a[i]^a[j])==k){
                //cout<<i<<' '<<j<<endl;
                ans++;
                i=j-1;
                break;
            }
        }
    }
    //cout<<a[1];
    //for(int i=2;i<=n;i++){
        //cout<<(a[i]^a[i-1]);
    //}
    cout<<ans;
    return 0;
}
