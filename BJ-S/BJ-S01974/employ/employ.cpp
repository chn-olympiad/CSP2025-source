#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int n,m;
string s;
int a[N],ton[N],qi[N];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i],ton[a[i]]++;
    int fl=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='1') fl=1;
    }
    if(!fl)
    {
        long long ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    sort(a+1,a+n+1);
    long long ans=1;
    for(int i=1;i<=n;i++)
    {
        int ke=0,ling=0,f=0,wei=0;
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='0') ling++;
            f+=qi[j-1];
            if(ling+f>=a[i])
            {
                wei=j;
                break;
            }
            ke++;
        }
       ans*=max(ke,1);
        ans%=mod;
        qi[wei]++;
    }
    cout<<ans;
    return 0;
}
