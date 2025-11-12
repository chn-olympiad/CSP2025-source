#include<bits/stdc++.h>
#define long long
using namespace std;

signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    int w[n+1];
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int zb=0;
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(w[j]>w[j-1]){
                zb=w[j-1];
                w[j-1]=w[j];
                w[j]=zb;
            }
        }
    }

    int ans=0;
    int jl=0;
    int anss[n+1],tows[n+1];
    for(int i=n-1;i>0;i--){
        jl++;
        //for(int j=)
    }



        cout<<ans;
    return 0;
}
