#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500010],k,b,ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        b=(b^a[i]);
        if(b>=k){
            if(b==k){
                ans++;
                //cout<<i<<endl;
            }
            b=0;
        }
    }
    cout<<ans;
    return 0;
}
