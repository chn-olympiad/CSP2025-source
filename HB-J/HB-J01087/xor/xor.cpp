#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int n,k,flag=1,flag2=1,a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) flag=0;
        if(a[i]>1) flag2=0;
    }
    ll ans=0;
    if(flag==1&&k==0)
    {
        cout<<n;
        return 0;
    }
    if(flag2==1&&k<=1)
    {
        if(k==0)
        {
            cout<<n;
            return 0;
        }
        if(k==1)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ans++;
                if(a[i]==0&&a[i+1]==0)
                {
                    ans++;
                    i++;
                }
            }
            cout<<ans;
            return 0;
        }
    }
    int c=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k) 
        {
            ans++;
            a[i]=-1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            c=-1;
            continue;
        }
        if(a[i]==k){ans++;continue;}
        if(c==-1) c=a[i];
        else if(c!=-1) c^=a[i];
        if(c==k)
        {
            ans++;
            c=-1;
        }
    }
    cout<<ans;
    return 0;
}