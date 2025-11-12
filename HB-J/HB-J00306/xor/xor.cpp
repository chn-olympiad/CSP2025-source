#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5e5+1;
bool ok;
int n,k,x,ans;
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>x;
        if(k==0){
            if(x==1){
                if(ok)
                    ++ans;
                else
                    ok=true;
            }
            else
                ++ans,ok=false;
        }
        else
            if(x)
                ++ans;
    }
    cout<<ans;
    return 0;
}
