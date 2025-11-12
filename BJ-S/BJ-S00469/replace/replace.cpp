#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,k;
string s;
struct node
{
    int u,v,w;
}a[1000005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i;
    cin>>n>>m>>k;
    for(i=1;i<=n;++i)
    {
        scanf("%d %d %d",&a[i].u,&a[i].v,&a[i].w);
    }
    
    sort(a+1,a+1+n);
    return 0;
}
