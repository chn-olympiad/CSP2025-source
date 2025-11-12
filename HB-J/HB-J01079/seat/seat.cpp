#include<bits/stdc++.h>
using namespace std;
struct node
{
    int numb;
    int data;
};
node a[100];
int ans1,ans2,m,n,r;
bool cmp(node x,node y)
{
    return x.data>y.data;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i].data);
        a[i].numb=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int now;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i].numb==1)
        {
            now=i;
            break;
        }
    }
    ans1=now/n;
    if(now%n)
        ans1++;
    ans2=now-ans1*(n-1);
    if(ans1%2==0)
        ans2=n-ans2+1;
    printf("%d %d",ans1,ans2);
    return 0;
}
