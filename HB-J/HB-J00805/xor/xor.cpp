#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct node{
    int l,r;
}q[200005];
int cct=0;
int dp[1005][1005];
int check(int x,int y)
{
    vector <int> nx,ny;
    if(x==0) nx.push_back(0);
    if(y==0) ny.push_back(0);
    int ans[105];
    int cnt=0;
    while(x!=0)
    {
        nx.push_back(x%2);
        x=x/2;
    }
    while(y!=0)
    {
        ny.push_back(y%2);
        y=y/2;
    }
    int maxx=nx.size(),maxy=ny.size();
    int maxn=int(max(maxx,maxy));
    for(int i=0;i<maxn;i++)
    {
        int hx,hy;
        if(i<maxx)
            hx=nx[i];
        else
            hx=0;
        if(i<maxy)
            hy=ny[i];
        else
            hy=0;
        if(hx==hy)
            ans[++cnt]=0;
        else
            ans[++cnt]=1;
    }
    int nci=1;
    int res=0;
    for(int i=1;i<=cnt;i++)
    {
        res+=ans[i]*nci;
        nci*=2;
    }
    return res;
}
bool cmp(node x,node y)
{
    if(x.r!=y.r)
        return x.r<y.r;
    return x.r-x.l<y.r-y.l;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        if(a[1]==k)
            cout<<"1";
        else
            cout<<"0";
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=a[i];
        if(dp[i][i]==k)
        {
            q[++cct].l=i;
            q[cct].r=i;
        }
        for(int j=i+1;j<=n;j++)
        {
            dp[i][j]=check(dp[i][j-1],a[j]);
            if(dp[i][j]==k)
            {
                q[++cct].l=i;
                q[cct].r=j;
            }
        }
    }
    sort(q+1,q+1+cct,cmp);
    int sum=0;
    int t=0;
    for(int i=1;i<=cct;i++)
    {
        if(q[i].l<=t)
            continue;
        sum++;
        t=q[i].r;
    }
    cout<<sum;
    return 0;
}
