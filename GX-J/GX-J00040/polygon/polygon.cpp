#include <bits/stdc++.h>
using namespace std;

int n,v[5001],qz[5001],f[5001];
int INF=998244353;

void dfs(int w,int x,long long z)
{
    if(w==x)
    {
        if(z>v[x])  f[x]++;
        return;
    }
    dfs(w+1,x,z+v[w]);
    dfs(w+1,x,z);
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    int ls=-1,mb=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(ls!=-1 && ls!=v[i])  mb=1;
        ls=v[i];
    }
    if(mb==0)
    {
        long long ans=1,c=n-3;
        for(int i=n;i>3;i--)
        {
            ans*=i;
            while(c>1 && ans%c==0)
            {
                ans/=c;
                c--;
            }
            ans%=INF;
        }
        cout<<ans<<endl;
        return 0;
    }

    sort(v+1,v+1+n);
    for(int i=1;i<=n;i++)   qz[i]=qz[i-1]+v[i];

    for(int i=n;i>0;i--)
    {
        if(qz[i]<=v[i]*2)   continue;
        dfs(1,i,0);
    }

    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=f[i];
    }
    cout<<ans<<endl;
    return 0;
}
