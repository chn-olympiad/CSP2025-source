#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[500005];
ll ans;
ll n,k;
bool vis[500005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n,&k);
    for(int i = 1;i<=n;++i){
        scanf("%lld",&arr[i]);
    }
    int fi=0,st=0;
    for(int j = 1;j<=n;++j){
        for(int i = 1;i<=n-j+1;++i){
            bool flag=0;
            int tmp=0;
            for(int k0=i;k0<=i+j-1;++k0){
                if(vis[k0]==1){
                    flag=1;
                    break;
                }
                tmp^=arr[k0];
            }
            if(flag)continue;
            if(tmp==k){
                fi=j+i-1;
                st= i;
                for(int t = st;t<=fi;++t){
                    vis[t] =1;
                }
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
