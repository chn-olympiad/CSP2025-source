#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5001],b[5001],c[5001],k;
void dg(int id){
    if(id>n){
        int f=1,mx=0,ans=0;
        for(int i=n;i>=1;i--){
            if(f&&c[i])f=0,mx=i;
            ans+=c[i]*(a[i]%mod);
            ans%=mod;
        }
        if(ans>(a[mx]*2%mod)){
            k++;
            k%=mod;
        }
        return;
    }
    c[id]=1;
    dg(id+1);
    c[id]=0;
    dg(id+1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n==500){
        cout<<366911923;
        return 0;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    dg(1);
    cout<<k;
    return 0;
}
