#include <bits/stdc++.h>
using namespace std;
long long n,k,a[50005],a2[50005],cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a2[i]=a2[i-1]^a[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if((a2[i]^a2[j])==k){
                cnt++;i=j-1;break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
