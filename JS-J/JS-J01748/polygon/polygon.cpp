#include <bits/stdc++.h>
using namespace std;
int n;
bool flag;
int a[1005];
int b[100005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    flag=true;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(b[i]!=1)
        {
            flag=false;
        }
    }
    if(flag)
    {
        long long zj=0,cb=0;
        for(int i=1;i<=n-2;i++)
        {
            cb+=i;
            zj+=cb;
            zj%=998244353;
        }
        cout<<zj;
        return 0;
    }
    int j=1;
    int ans=0;
    while(a[n+1]==0)
    {
        j=1;
        while(a[j]!=0)
        {
            j++;
        }
        a[j]=1;
        for(int i=1;i<j;i++)
        {
            a[i]=0;
        }
        int cnt=0;
        int maxx=INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(a[i])
            {
                cnt+=b[i];
                maxx=max(maxx,b[i]);
            }
        }
        if(cnt>2*maxx) ans++;
    }
    cout<<ans;
    return 0;
}
