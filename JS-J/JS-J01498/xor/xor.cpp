#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    #ifndef NOFREOPEN
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    #endif // NOFREOPEN
    int n,k,ans=0,res=0;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res^=a[i];
        if(res==k){
            ans++;
            res=0;
        }
    }
    int tans=0;
    res=0;
    for(int i=n;i;i--){
        res^=a[i];
        if(res==k){
            tans++;
            res=0;
        }
    }
    cout<<max(ans,tans);
}
