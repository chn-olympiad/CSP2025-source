#include <bits/stdc++.h>
using namespace std;
long long n,m,c[505],a[505],ans,flag1=0,flag2=0;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==1) flag1++;
        if(s[i-1]=='1') flag2++;
        a[i]=i;
    }
    if((flag1==0)||(flag2==0))
    {
        cout<<0;
        return 0;
    }
    if(flag1==n&&flag2==n)
    {
        ans=1;
        for(long long i=1;i<=n;i++)
        {
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    if(n<=10)
    {
        do
        {
            long long sum=0;
            for(long long i=1;i<=n;i++)
            {
                if(sum>=c[a[i]]||s[i-1]=='0')
                {
                    sum++;
                }
            }
            if(n-sum>=m)
            {
                ans++;
                ans%=998244353;
            }
        }while(next_permutation(a+1,a+1+n));
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        ans=1;
        for(long long i=1;i<=n;i++)
        {
            ans*=i;
            ans%=998244353;
        }
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        cout<<0;
        return 0;
    }
    return 0;
}
