#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn=1e5+5;
int n,ans;
struct node
{
    int id,x1,x2,x3;
}a[maxn];
bool cmp1(node a,node b)
{
    if(a.x1!=b.x1)return a.x1>b.x1;
    if(a.x2!=b.x2)return a.x2>b.x2;
    return a.x3>b.x3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            a[i].id=i;
            cin>>a[i].x1>>a[i].x2>>a[i].x3;
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n>>1;i++)
        {
            ans+=a[i].x1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
