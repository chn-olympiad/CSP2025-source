#include<bits/stdc++.h>
using namespace std;
long long a[10000005],cnt,sum;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long n,m,k;
    cin>>n>>m>>k;
    for(long long i=1;i<=m;i++){
        long long x,y,z;
        cin>>x>>y>>z;
        a[++cnt]=z;
    }

    for(long long i=1;i<=k;i++){
        long long x;
        for(long long j=1;j<=n;j++){
            long long y;
            cin>>y;
            a[++cnt]=y+x;
        }
    }
    sort(a+1,a+cnt+1);
    for(long long i=1;i<=cnt;i++){
        sum+=a[i];
    }
    cout<<sum;
    return 0;
}
