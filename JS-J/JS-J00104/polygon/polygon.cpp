#include <bits/stdc++.h>
using namespace std;
const int maxn=5002;
const int mod=998244353;
int n;
long long ans=0;
int a[maxn],sum[maxn],maxl[maxn];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n<=3){
        if(n==3&&a[1]+a[2]>a[3]&&a[3]-a[2]<a[1]) ans++;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        maxl[i]=max(maxl[i-1],a[i]);
    }
    return 0;
}
