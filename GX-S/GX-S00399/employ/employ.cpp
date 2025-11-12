#include<bits/stdc++.h>
using namespace std;
int sum=0,a,b,e[505];
string ciii;
void dfs(bool c[],int d,int l,int pp,int k)
{
    if(k==d)
    {
        if(pp>=b) sum++;
        sum%=998244353;
        return;
    }
    for(int i=0;i<d;i++)
    {
        if(c[i]==0)
        {
            if(l>=e[i] || ciii[k]=='0')
            {
                bool ci[d];
                for(int j=0;j<d;j++) ci[j]=c[j];
                ci[i]=1;
                dfs(ci,d,l+1,pp,k+1);
            }
            else
            {
                bool ci[d];
                for(int j=0;j<d;j++) ci[j]=c[j];
                ci[i]=1;
                dfs(ci,d,l,pp+1,k+1);
            }
        }
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>a>>b;
    cin>>ciii;
    bool ccccc[a]={0};
    for(int i=0;i<a;i++) cin>>e[i];
    dfs(ccccc,a,0,0,0);
    cout<<sum%998244353;
    return 0;
}
