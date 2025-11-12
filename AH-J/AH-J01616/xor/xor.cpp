#include<bits/stdc++.h>
#define long long
using namespace std;

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int yh[n+1];
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>yh[i];
    }

    int jl=0;
    if(k!=0){
        for(int i=1;i<=n;i++){
        if(yh[i]==k){
            ans++;
        }
        else{
            jl=jl^yh[i];
            if(jl==k){
                ans++;
            }
        }
    }
    }
    else{
        for(int i=1;i<=n;i++){
        if(yh[i]==k){
            ans++;
        }
        else{
            if(yh[i]==jl){
                ans++;
                jl=0;
            }
            else{
                jl=yh[i];
            }
        }
    }
    }


    cout<<ans;
    return 0;
}
