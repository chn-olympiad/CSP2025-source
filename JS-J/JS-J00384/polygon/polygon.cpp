#include <bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,t,cnt[5005],a[5005];
bool f;
long long ans,x;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    x=1,f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) f=0;
    }
    if(f){
        x=n-2;
        cnt[1]=1;
        ans=1;
        for(int i=2;i<=x;i++)
            cnt[i]=cnt[i-1]+i;
        for(int i=1;i<=x;i++){
            ans+=cnt[i];
        }
    }
    else{
        sort(a+1,a+n+1);
        for(int i=3;i<=n;i++){
            x=0;
            for(int j=1;j<i;j++) x+=a[j];
            for(int j=i;j<=n;j++){
                if(a[j]<x) ans++;
                ans%=M;
                x=x-a[j-i+1]+a[j];
            }
        }
    }

    cout<<ans;
    return 0;
}
