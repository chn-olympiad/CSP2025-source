#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int a[500];
int d[500];
int w[500]={0};
void dfs(int s,int f,int day)
{
    if(day==n)
        return;
    if(s>=m)
    {
        sum++;
        sum=sum%998244353;
        return;
    }
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(f>=d[i] && w[i]==0)
        {
            w[i]=day+1;
            t++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w[i]==0)
        {
            w[i]=day+1;
            if(a[day]==1)
                dfs(s+1,f+t,day+1);
            else
                dfs(s,f+1+t,day+1);
            w[i]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w[i]==day+1)
            w[i]=0;
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        char s;
        cin>>s;
        a[i]=s-'0';
    }
    for(int i=0;i<n;i++)
        cin>>d[i];
    dfs(0,0,0);
    cout<<sum;
    return 0;
}
