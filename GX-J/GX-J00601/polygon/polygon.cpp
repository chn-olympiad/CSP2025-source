#include <bits/stdc++.h>
using namespace std;
long long a[5005],n;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    long long maxn=-1,zong=0;
    for(int i=1;i<=n;i++)
    {
        zong+=a[i];
        maxn=max(maxn,a[i]);
    }
    if(zong>2*maxn)
    {
        ans++;
    }
    cout<<ans;
    return 0;
}
