#include<bits/stdc++.h>
using namespace std;
struct node
{
    int id,val;
}a[105];
bool cmp(node a,node b)
{
    return a.val>b.val;
}
int main()//100
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        int x;
        scanf("%d",&x);
        a[i]={i,x};
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(i<=n&&a[i].id==1)
        {
            printf("1 %d",i);
            break;
        }
        if(a[i].id==1)
        {
            if(((i%n==0)?i/n:i/n+1)%2==1)
            {
                printf("%d %d",(i%n==0)?i/n:i/n+1,(i%n==0)?n:(i%n));
            }
            else
            {
               printf("%d %d",(i%n==0)?i/n:(i/n+1),(i%n==0)?1:n-(i%n)+1);
            }
            break;
        }
    }
}

