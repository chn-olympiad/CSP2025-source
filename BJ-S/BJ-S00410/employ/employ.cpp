#include<bits/stdc++.h>
using namespace std;
int n,m,em[505],a[505],cnt1,cnt2,a1[505],cnt=1;
string s;
int ok()
{
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}
int ok1(int n1)
{
    int ans=1;
    for(int i=1;i<=n1;i++)
    {
        ans*=i;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            em[i]=1;
            cnt1++;
        }
        else
        {
             em[i]=0;
             cnt2++;
        }
    }
    if(cnt1==n)
    {
        cout<<ok()%998244353;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a1[a[i]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(a1[i]>1)
        {
            cnt*=ok1(a1[i]);
        }
    }
    cout<<cnt%998244353;
    return 0;
}