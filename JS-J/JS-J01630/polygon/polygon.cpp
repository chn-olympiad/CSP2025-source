#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
long long num=0;
bool vis[5001];
bool cmp(int a,int b)
{
    return a>b;
}

void count(int x,int h,int z,int dep)
{
    if(h>2*z&&dep>=3)
    {
        num++;
    }
    for(int i=x+1;i<=n;i++)
    {
        count(i,h+a[i],z,dep+1);
    }
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        count(i,a[i],a[i],1);
    cout<<num;
}
