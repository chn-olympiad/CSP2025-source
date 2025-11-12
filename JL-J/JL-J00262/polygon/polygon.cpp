#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=998244353,N=5e3+5;
int n,a[N];
ll cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int l=1,r=n,len=0;
    while(r-l>=2){
        for(int i=l;i<=r;i++)
            len+=a[i];
        if(len>a[r]*2){
            cnt++,cnt%=MOD;
        }
        x=len-a[r]*2;
        for(int i=l+1;i<r;i++)
            if(a[i]<x && r-l-1>=2)
                cnt++,cnt%=MOD;
        l++,len=0;
    }
    l=1,r=n-1;
    while(r-l>=2){
        for(int i=l;i<=r;i++)
            len+=a[i];
        if(len>a[r]*2)
            cnt++,cnt%=MOD;
        x=len-a[r]*2;
        for(int i=l+1;i<r;i++)
            if(a[i]<x && r-l-1>=2)
                cnt++,cnt%=MOD;
        r--,len=0;
    }
    printf("%lld",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
