#include<bits/stdc++.h>
using namespace std;
long long qa[200001];
int a[200001],zl[200001],zr[200001],w,ans;
bool g[300],u[500001];
void dg(int sum)
{
    for(int i=1;i<=w;i++)
    {
        if(!u[i])
        {
            int wj=zl[i]-1;
            bool f=0;
            u[i]=1;
            for(int j=zl[i];j<=zr[i];j++)
            {
                if(!g[j])
                {
                    g[j]=1;
                }
                else
                {
                    ans=max(ans,sum);
                    f=1;
                    break;
                }
                wj=j;
            }
            if(!f)
            {
                dg(sum+1);
                for(int j=zl[i];j<=zr[i];j++)
                 {
                   g[j]=0;
                 }
            }
            else
            {
                for(int j=zl[i];j<=wj;j++)
                {
                    g[j]=0;
                }
            }
            u[i]=0; 
        }
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        qa[i]=qa[i-1]^a[i];
    }
    for(int l=1;l<=n;l++)
    {
        for(int r=l;r<=n;r++)
        {
            if((qa[r]^qa[l-1])==k)
            {
                w++;
                zl[w]=l;
                zr[w]=r;
            }
        }
    }
    dg(0);
    cout<<ans;
    return 0;
}