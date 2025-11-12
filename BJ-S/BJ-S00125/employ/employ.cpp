#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int nd[505],c[505],num[505];
const long long MOD=998244353;
long long ans=0;
bool check()
{
    int fail=0,cango=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(nd[i]==0)
        {
            fail++;
            continue;
        }
        if(fail>=c[num[i]])
        {
            fail++;
            continue;
        }
        cango++;
        if(cango>=m)
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        num[i]=i;
    }
    for(int i=1;i<=n;i++)
    {
        nd[i]=s[i-1]-'0';
    }
    do
    {
        if(check())
        {
            ans++;
            ans%=MOD;
        }
    }
    while(next_permutation(num+1,num+n+1));
    cout<<ans;
    return 0;
}
