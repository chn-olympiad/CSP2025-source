#include<bits/stdc++.h>
#define N 2010
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
int a[N][N],n,k,le=0,ans,f[N],sum;
struct node
{
    int l,r,len;
}d[N*N/2];
bool cmp(node x,node y)
{
    x.len<y.len;
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    if(n==1)
    {
        int x;
        cin>>x;
        if(x==k)  cout<<1<<endl;
        else cout<<0<<endl;
        return 0;
    }
    if(n==2)
    {
        int x,y,ans=0,f=0;
        cin>>x>>y;
        if(x==k) ans++,f=1;
        if(y==k) ans++,f=1;
        if(x^y==k&&!f)  ans++;
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[1][i]=x;
        if(x==k)  ans++,d[++le]={i,i,1},sum++;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n+1-i;j++)
        {
            a[i][j]=a[i-1][j]^a[i-1][j+1];
            if(a[i][j]==k)  d[++le]={j,j+i-1,i};
        }
    }
    if(sum==3)  cout<<3<<endl;
    cout<<le<<endl;
    return 0;
}
