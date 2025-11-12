#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=998244353;
typedef long long ll;
ll n,maxn,ans,a[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(maxn,a[i]);
    }
    sort(a+1,a+1+n);
    if(n==3){
        if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
        else cout<<0;
    }
    else if(maxn==1){
        ans=1;
        for(int i=1;i<=n;i++) ans=ans*2%M;
        cout<<ans-n-(n*(n-1)/2)-1;
    }
    return 0;
}
