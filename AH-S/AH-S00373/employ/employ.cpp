#include<iostream>
using namespace std;
const long long MOD=998244353;
int n,a[505],num[505],l[505],nl,t,m;
long long ans=0;
string s;
long long dfs(int i,int bf,int f)
{
    if(n-bf-f<m)
    {
        return 0;
    }
    //cout<<"***"<<i<<' '<<bf<<' '<<f<<'|';
    for(int j=t;j<=nl;j++)
    {
        //cout<<j<<' '<<num[l[j]]<<'|';
    }
    int t0=t;
    if(i==n)
    {
        if(f>0 || s[i-1]=='0')
        {
            return n-bf-1 >= m;
        }
        else
        {
            //cout<<"{"<<int(n-bf >= m)<<"}";
            return n-bf >= m;
        }
    }
    //cout<<"+";
    while(l[t]<=bf)
    {
        t++;
    }
    //cout<<"<"<<t<<">"<<endl;;
    long long kans=0;
    if(f>0)
    {
        kans=kans+dfs(i+1,bf+1,f+num[bf+1]-1)*f;
    }
    if(s[i-1]=='1')
    {
        for(int j=t;j<=nl;j++)
        {
            if(num[l[j]]<=0)
            {
                continue;
            }
            num[l[j]]--;
            kans=(kans+ ((dfs(i+1,bf,f)*(num[l[j]]+1))%MOD))%MOD;
            num[l[j]]++;
        }
    }
    else
    {
        for(int j=t;j<=nl;j++)
        {
            if(num[l[j]]<=0)
            {
                continue;
            }
            num[l[j]]--;
            kans=(kans+ ((dfs(i+1,bf+1,f+num[bf+1])*(num[l[j]]+1))%MOD))%MOD;
            num[l[j]]++;
        }
    }
    t=t0;
    return kans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        num[x]++;
    }
    for(int i=0;i<=n;i++)
    {
        if(num[i]>0)
        {
            l[++nl]=i;
        }
    }
    t=1;
    ans=dfs(1,0,num[0]);
    cout<<ans;
    return 0;
}
