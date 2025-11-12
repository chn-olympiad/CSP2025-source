#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m;
int mod=998244353;
int c[5050];
long long ans;
long long cnt1=1,cnt2=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    for(int i=1;i<=n;i++)
    {
        cnt1=cnt1*i%mod;
    }
    if(n==m)
    {
        cout<<cnt1<<endl;
        return 0;
    }
    if(m==1)
    {
        int x=0;
        for(int i=0;i<s.size();i++)
        {
            x++;
            if(s[i]=='1')
            {
                break;
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]>=x)
            {
                sum++;
            }
        }
        long long sum2=1;
        for(int i=1;i<=n-1;i++)
        {
            sum2=sum2*i%mod;
        }
        cout<<sum*sum2%mod<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
       cnt2=cnt2*i%mod;
    }
    //cout<<cnt1<<endl<<cnt2<<endl<<cnt3<<endl;
    ans=(cnt1/cnt2%mod);
    cout<<ans<<endl;
    return 0;
}
