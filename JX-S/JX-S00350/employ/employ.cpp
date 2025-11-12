#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,a[505],b[505];
bool ny[505],xx[505];
int dfs(int sum)
{
    if(sum==n)
    {
        int sum1=0;
        for(int i=1;i<=n;i++)
        {
            if((ny[i]==1)&&(b[i]<=i))
                sum1++;
        }
        if(sum1>=m)
            return 1;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(!xx[i])
        {
            b[sum]=a[i];
            xx[i]=1;
            ans+=dfs(sum+1);
            ans%=998244353;
            xx[i]=0;
        }
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >>n>>m;
    cin >>s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            ny[i+1]=0;
        else
            ny[i+1]=1;
    }
    for(int i=1;i<=n;i++)
        cin >>a[i];
    cout <<dfs(1);
    return 0;
}
