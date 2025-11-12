#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e3+10;
const long long p=998244353;

long long int n,ans,sum;
long long int a[MAXN];
long long int f[MAXN];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum=(sum*2%p+i-1)%p;
        for(int j=1;j<=a[i];j++){
            if(f[j]>0){
                ans=(ans+f[j])%p;
            }
        }
        for(int j=5000;j>=a[i];j--){
            if(f[j-a[i]]>0){
                f[j]=(f[j-a[i]]+f[j])%p;
            }
        }
        for(int j=1;j<i;j++){
            if(a[i]+a[j]>5000) break;
            f[a[i]+a[j]]=(f[a[i]+a[j]]+1)%p;
        }
    }
    ans=(ans+n*(n-1)/2)%p;
    if(sum>ans) cout<<(sum-ans)%p;
    else cout<<(p+sum-ans)%p;
    return 0;
}
//Well I don't think I can get 400 pts
//please let me get S1 in the afternoon...
//please...ccf...
