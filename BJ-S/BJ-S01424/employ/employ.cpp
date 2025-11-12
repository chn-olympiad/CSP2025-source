#include <bits/stdc++.h>
using namespace std;
const long long N=998244353;
int a[100010];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        long long ans=1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                cout<<"0";
                return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans=(ans*(i%N))%N;
        }
        cout<<ans;
        return 0;
    }
    if(m==1)
    {
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='0') tmp++;
                if(tmp>=a[i]&&tmp!=0) break;
                else if(s[j]=='1') ans++;
            }
        }
        ans=ans%N;
        for(int i=1;i<n;i++)
        {
            ans=(ans*(i%N))%N;
        }
        cout<<ans;
        return 0;
    }
    int aaa=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            aaa=1;
        }
    }
    if(aaa==0) cout<<"0";
    return 0;
}
