#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,k,mx,a[N],b[N];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    //special B
    if(1){
        for(int i=1;i<=n;i++) b[i]=(b[i-1]+a[i])%2;
        int cnt[2]={0,0};
        if(k==0){
            cnt[1]--;
            for(int i=1;i<=n;i++){
                cnt[b[i]]++;
            }
        }
        else if(k==1){
            for(int i=1;i<=n;i++){
                cnt[b[i]]=cnt[(!b[i])]+1;
            }
        }
        cout<<max(cnt[0],cnt[1]);
    }
    return 0;
}
