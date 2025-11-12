#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],cnt0,cnt1,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) cnt0++;
        if(a[i]==1) cnt1++;
    }
    if(cnt0+cnt1==n)
    {
        if(k==1) cout<<cnt1;
        if(k==0)
        {
            cnt0=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1&&a[i+1]==1) a[i]=0,a[i+1]=-1;
                if(a[i]==0) cnt0++;
            }
            cout<<cnt0;
        }
        return 0;
    }
    
    return 0;
}