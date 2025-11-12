#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
int a[5010];
#define N 998244353
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int len,int x,int maxn,int sumlen)
{
    if(len>=3&&x<=n&&maxn*2<sumlen)
    {
        int y=n-x;
        cnt=(cnt+y*(y+1)/2+1)%N;
        return;
    }
    else
    {
        if(x>n) return;
        else
        {
            dfs(len+1,x+1,maxn,sumlen+a[x+1]);
            dfs(len,x+1,maxn,sumlen);
        }
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n-2;i++)
    {
        dfs(1,i,a[i],a[i]);
    }
    cout<<cnt;
    return 0;
}
