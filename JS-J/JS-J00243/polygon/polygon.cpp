#include<bits/stdc++.h>
using namespace std;
int a[50005]={};
int n;
int cnt=0;
void dfs(int x,int c,int maxn,int sum)
{
    if(c+n-x+1<3)return;
    if(x>n)
    {
        if(c>=3&&sum>2*maxn)
        {
            cnt++;
        }
        return;
    }
    dfs(x+1,c+1,max(maxn,a[x]),sum+a[x]);
    dfs(x+1,c,maxn,sum);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}
