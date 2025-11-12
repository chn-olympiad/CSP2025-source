#include <bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int modn=998244353;

int n,a[maxn];
long long p[maxn];

int main(){

    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    p[0]=1;
    for (int i=1;i<=5000;i++){
        p[i]=p[i-1]*p[i]%modn;
    }

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    sort(a+1,a+n+1);

    long long ans=0;
    for (int i=3;i<=n;i++){
        ans=(ans+(p[n]/p[(n-i)]/p[i])%modn)%modn;
    }

    cout<<ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
