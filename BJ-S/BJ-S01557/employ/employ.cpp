#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int c[505],a[505];
bool check(string s)
{
    for(int i=0;i<s.size();i++)
        if(s[i]=='0')
            return false;
    return true;
}
void ezans(int n)
{
    int ans=1,res=0;
    for(int i=1;i<=n;i++)
        if(!c[i])
            res++;
    for(int i=1;i<=n;i++)
        if(c[i]<=res)
            res++;
    for(int i=1;i<=n;i++)
        if(c[i]<=res)
            res++;
    n-=res;
    for(int i=1;i<=n;i++)
        ans=ans*i%mod;
    cout<<ans;
    return;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string dif;
    cin>>dif;
    for(int i=1;i<=n;i++)
        cin>>c[i],a[i]=i;
    int ans=0;
    do
    {
        int out=0;
        for(int i=1;i<=n;i++)
        {
            //cout<<a[i]<<" ";
            if(out>=c[a[i]]||dif[i-1]=='0')
                out++;
            if(n-out<m)
                break;
        }
        if(n-out>=m)
            ans++;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
