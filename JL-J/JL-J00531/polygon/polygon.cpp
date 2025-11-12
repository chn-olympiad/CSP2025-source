#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];
bool fun(int a[],int b,int c,int d,int e)
{
    int s=0,maxn=-1;
    s=a[c]+a[d]+a[e];
    maxn=max(max(a[c],a[d]),a[e]);
    if(s>maxn*2 && c!=d!=e) return 1;
    else return 0;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=j+1;k<=n;k++)
                for(int d=k+1;d<=n;d++)
                    if(fun(a,i,j,k,d)==1) ans++;
    }
    printf("%d\n",ans%998%244%353);
    return 0;
}
