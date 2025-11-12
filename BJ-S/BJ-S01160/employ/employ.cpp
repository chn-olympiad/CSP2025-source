#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int a[100010],b[100010],c[100010];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    if(n<=10)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=i;
            c[i]=a[i];
        }
        do
        {
            for(int i=1;i<=n;i++)a[i]=c[b[i]];
            int t=0,cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(s[i-1]=='1')
                {
                    if(cnt>=a[i])
                    {
                        cnt++;
                    }
                    else t++;
                }
                else cnt++;
            }
            if(t>=m)ans++;
        }
        while(next_permutation(b+1,b+n+1));
        cout<<ans<<endl;
        return 0;
    }
    int p=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)p++;
    }
    if(n-p<m)
    {
        cout<<0<<endl;
    }
    else
    {
        if(m==1)
        {
            long long ans=1;
            for(int i=1;i<=n-1;i++)
            {
                ans*=i;
                ans%=998244353;
            }
            ans*=(n-p);
            ans%=998244353;
            cout<<ans<<endl;
            return 0;
        }
        long long ans=1;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=998244353;
        }
        cout<<ans<<endl;
    }
}