#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],s,ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]%2==0) s=0;
        else s=1;
        for(int j=i;j<=n;j++){
            s^=a[j];
            if(s==k){
                ans++;
                i=j;
            }
            if(s>k) break;
        }
    }cout<<ans;
    return 0;
}
//#Shang4Shan3Ruo6Shui4
