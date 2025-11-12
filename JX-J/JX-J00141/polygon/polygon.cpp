#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long a[5005];
long long n,j,sum,cnt,ii,maxn,kk;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    sum=1<<n;
    sum-=1;
    for(long long i=1;i<=sum;i++){
        j=i;
        cnt=0;
        ii=0;
        maxn=0;
        while(j){
            ++ii;
            if(j&1==1){
                cnt+=a[ii];
                maxn=max(maxn,a[ii]);
            }
            j>>=1;
        }
        if(cnt>2*maxn){
            kk=(kk+1)%mod;
        }

    }
    cout<<kk;
    return 0;
}
