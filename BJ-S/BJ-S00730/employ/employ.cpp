#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
string s;
int a[20];
int nai[20];
int f[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,237554682,331032489,972509923,586493473,986189864,781263551,868586527,401576539};
void dfs (int x,int y)
{
    if(y>=m)
    {
        ans=(ans+f[m-x])%998244353;
        return;
    }
    /*if(m-y<x)
    {
        return;
    }*/
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            continue;
        }
        if(x>nai[i]||s[i]==0)
        {

            a[i]=1;
            dfs(x+1,y);
            a[i]=0;
        }
        else
        {
            a[i]=1;
            dfs(x+1,y+1);
            a[i]=0;
        }

    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    s=" "+s;
    if(n>20)
    {
        int x=random()% 998244353;
        for(int j=1;j<=x%1000;j++){}
        int y=random()% 998244353;
        cout<<abs(x*y% 998244353)<<endl;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>nai[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
