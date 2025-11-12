#include<bits/stdc++.h>
using namespace std;
int n,ans,maxn;
int a[50005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    maxn=max(a);
    for(int i=1;i<=n;i++){
        if(a[i]+a[i+1]+a[i+2]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+3]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+4]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+2]+a[i+3]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+2]+a[i+4]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+3]+a[i+4]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+2]+a[i+3]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+2]+a[i+4]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+3]+a[i+4]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+3]+a[i+4]>=2*maxn){
            ans++;
        }
        if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>=2*maxn){
            ans++;
        }
    }
    cout<<ans;
}
