#include<bits/stdc++.h>
using namespace std;
int mn=100000000,mx,zg,ans,a[100005];
long long k,n,xr[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    xr[1]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        if(a[i]==0) zg++;
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
        xr[i]=xr[i-1]^a[i];
    }
    if(mn==mx==1){
        cout<<n;
        return 0;
    }
    if(mn==0&&mx==1){
        cout<<zg;
        return 0;
    }
    for(int i=1,j=1;i<=n;i++){
        while(xr[i]^xr[j]!=k&&j!=n) j++;
        if(xr[i]^xr[j]==k) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

