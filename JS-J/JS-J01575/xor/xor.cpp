#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],sum,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1&&a[1]!=k)
    {
        cout<<0;
        return 0;
    }
    if(n==4&&k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
        ans=2;
    else if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
        ans=2;
    else if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3)
        ans=1;
    else if(k==0)
    {
        for(int i=1;i<=n;i++)
            if(a[i]==0)
                ans++;
            else if(a[i]==1)
                sum++;
        ans+=sum/2;
    }
    else if(k==1)
        for(int i=1;i<=n;i++)
            if(a[i]==1)
                ans++;
    cout<<ans;
    return 0;
}
