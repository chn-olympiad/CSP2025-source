#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],i,j,l,ans=0,cnt,ma=-1;
int main(){
    ///*
    freopen("pologon.in","r",stdin);
    freopen("pologon.out","w",stdout);
    //*/
    scanf("%lld",&n);
    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            cnt=0;
            ma=-1;
            for(l=i+1;l<=j;l++)
            {
                ma=max(a[i],ma);
                cnt+=a[i];
            }
            if(j-i>=3&&cnt>ma*2) ans=(ans+1)%998244353;
        }
    }
    cout<<ans;
    return 0;
}
/*

5000^3=125,000,000,000

*/
