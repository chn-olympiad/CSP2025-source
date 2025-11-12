#include<bits/stdc++.h>
using namespace std;
int n,flaga,flagb;
long long k,a[500002],s,sum,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)flaga=1;
        if(a[i]!=0&&a[i]!=1)flagb=1;
    }
    if(flaga==0&&k==0)
    {
        cout<<0;
        return 0;
    }
    if(flagb==0)
    {
        for(int i=1;i<=n;i++)if(a[i]==k)ans++;
        cout<<ans;
        return 0;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            s=a[i];
            sum=0;
            for(int j=i;j<=n;j++)
            {
                if(s==k)
                {
                    s=a[j+1];
                    sum++;
                    continue;
                }
                if(s==a[j])continue;
                s=(s xor a[j]);
                if(s==k)
                {
                    s=a[j+1];
                    sum++;
                    continue;
                }
            }
            ans=max(ans,sum);
        }
        cout<<ans;
    }
    return 0;
}
