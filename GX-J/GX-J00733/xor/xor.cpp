#include<bits/stdc++.h>
using namespace std;
int c[500005],a,b;
map<int,map<int,int>> p;
int dfs(int l,int r)
{
    if(p[l][r]!=0)
        return p[l][r];
    int sum=c[l];
    if(l==r) sum=c[l];
    else
        for(int i=l+1;i<=r;i++)
            sum=sum^c[i];
    int o;
    if(sum==b) o=1;
    else o=0;
    int sum1=0;
    if(r!=a-1)
        for(int i=0;r+1+i<a;i++)
        {
            sum1=max(o+dfs(r+1,r+1+i),sum1);
        }
    else
    {
        p[l][r]=o;
        return o;
    }
    p[l][r]=sum1;
    return sum1;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>a>>b;
    int sum=0;
    for(int i=0;i<a;i++) cin>>c[i];
    for(int i=0;i<a;i++)
    {
        sum=max(dfs(0,i),sum);
    }
    cout<<sum;
    return 0;
}
