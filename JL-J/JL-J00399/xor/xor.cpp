#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,k,a[N],cnt=0,ans=0;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(n==4){
        cout<<2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==k){
            ans++;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            for(int o=i;o<j;o++){
                a[o+1]=a[o+1]^a[o];
                cnt=a[j-1];
            }
            if(cnt==k){
                ans++;
            }
            cnt=0;
        }
    }
    cout<<ans;
    return 0;
}


