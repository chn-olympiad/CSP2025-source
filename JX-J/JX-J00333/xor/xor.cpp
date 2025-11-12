#include <bits/stdc++.h>
using namespace std;
constexpr int N=500005;
long long n,k,ans=0,cnt=1;
int pre[N];
bitset<1<<21> cz;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cz[0]=1;
    for (int z=1;z<=n;z++){
        cin>>pre[cnt];
        pre[cnt]^=pre[cnt-1];
        if (cz[pre[cnt]^k]){
            ++ans;
            for (int y=1;y<cnt;y++){
                cz[pre[y]]=0;
            }
            cz[0]=1;
            cnt=1;
        }else{
            cz[pre[cnt++]]=1;
        }
    }
    cout<<ans;
    cout<<'\n';
    return 0;
}
