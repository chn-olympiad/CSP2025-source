#include<bits/stdc++.h>
using namespace std;
int a[102];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
        if(i==1)ans=a[i];
    }
    sort(a+1,a+1+n*m);
    int pos;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ans)pos=i;
    }
    pos=n*m+1-pos;
    int x=pos/n,y=pos%n;
    if(x%2==1)
    {
        if(y==0)printf("%d %d",x,n);
        else printf("%d %d",x+1,n+1-y);
    }
    else
    {
        if(y==0)printf("%d %d",x,1);
        else printf("%d %d",x+1,y);
    }
    return 0;
}
