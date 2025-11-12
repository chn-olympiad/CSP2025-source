#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500005],ans;
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=7;i<=(2<<n);i++){
        int sum=0,mx=0;
        for(int w=0;w<n;++w){
            if(i&(1<<w)){
                sum+=a[w];
                mx=max(mx,a[w]);
            }
        }
        if(sum>mx*2) ans++;
    }
    cout<<ans/2;
    return 0;
}
