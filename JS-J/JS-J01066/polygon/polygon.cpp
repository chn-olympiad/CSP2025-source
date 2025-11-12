#include<bits/stdc++.h>
using namespace std;

int a[5000],ans[5000];
bool f[5000];
long long s=0;
int n;
void dfs(int m,int step,int t)
{
    if(m==step)
    {
        long long x=0;
        int maxn=0;
        for(int i=0;i<m;i++)
        {
            x+=ans[i];
            maxn=max(maxn,ans[i]);
        }
        if(x>2*maxn)
        {
            s++;
            s%=998244353;
        }
        return;
    }
    for(int i=t+1;i<n;i++)
    {
        if(!f[i])
        {
            f[i]=true;
            ans[step]=a[i];
            dfs(m,step+1,i);
            f[i]=false;
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n<=20)
    {
        for(int i=3;i<=n;i++)
        {
            dfs(i,0,-1);
        }
        cout<<s;
    }else{
        for(int i=3;i<=n;i++)
        {
            long long b=1,c=1,d=1,e=0;
            for(int j=0;j<i;j++)
            {
                b*=d;
                c*=n-e;
                d++;
                e++;
            }
            s=s+(c%998244353)/(b%998244353);
            s%=998244353;
        }
        cout<<s;
    }
    return 0;
}
