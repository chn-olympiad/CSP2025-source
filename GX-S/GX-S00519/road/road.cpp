#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ar[10009]={0};
int ans=0;
int a[11][10009]={0};
struct Node
{
    int a,b,c;
};
Node arr[1000009];
bool cmp(Node x,Node y)
{
    return x.c<y.c;
}
int f(int t)
{
    if(ar[t]==t)
        return t;
    return ar[t]=f(ar[t]);
}
void bing(int q,int p)
{
    int q1=f(q);
    int p1=f(p);
    ar[q1]=p1;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>arr[i].a>>arr[i].b>>arr[i].c;
    sort(arr+1,arr+m+1,cmp);
    for(int i=1;i<=n;i++)
        ar[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(f(arr[i].a)!=f(arr[i].b))
        {
            bing(arr[i].a,arr[i].b);
            ans+=arr[i].c;
        }
    }
    cout<<ans;
    return 0;
}
