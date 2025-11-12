#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[111111],n;
long long ans=0;
void dfs(int x,int t)
{
    for(int i=x+1;i<n;i++)
    {
        if(t>a[i])
        {
            ans++;
        }
            
        dfs(i,t+a[i]);
    }
    ans%=M;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
        dfs(i,a[i]);
    }
    cout<<ans;
    return 0;
}