#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int a,b,c;
}a[100002];
int b[100002];//,dp[2][202][202][202];//dp[i][j][k][l]表示前i个人 j个1 k个2 l个3 的最大
int maxn,n,cnt=0;
bool cmp(Node a,Node b)
{
    if(a.a==b.a)
    {
        if(a.b==b.b)
            return a.c>b.c;
        return a.b>b.b;
    }
    return a.a>b.a;
}
void DFS(int x,int sa,int sb,int sc,int sum)
{
    if(x==n+1)
    {
        maxn=max(maxn,sum);
        return;
    }
    if(sa>0)
        DFS(x+1,sa-1,sb,sc,sum+a[x].a);
    if(sb>0)
        DFS(x+1,sa,sb-1,sc,sum+a[x].b);
    if(sc>0)
        DFS(x+1,sa,sb,sc-1,sum+a[x].c);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        maxn=0;
        bool f=true;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            b[++cnt]=a[i].a;
            if(a[i].b!=0||a[i].c!=0)
                f=false;
        }
        if(f)//A
        {
            sort(b+1,b+cnt+1);
            int sum=0;
            for(int i=cnt;i>=n/2+1;i--)
                sum+=b[i];
            cout<<sum<<"\n";
            continue;
        }
        if(n<=10)
        {
            DFS(1,n/2,n/2,n/2,0);
            cout<<maxn<<"\n";
            continue;
        }
        sort(a+1,a+n+1,cmp);
        int sum=0;
        for(int i=n;i>=1;i--)
        {
            if(n-i+1<=n/2)
                sum+=a[i].a;
            else
                sum+=a[i].b;
        }
        cout<<sum<<"\n";
    }
    return 0;
}