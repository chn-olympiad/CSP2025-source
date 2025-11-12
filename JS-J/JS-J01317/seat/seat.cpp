#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,b[105];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&b[i]);
    }
    int x=b[1];
    for(int i=1;i<=100;i++)
    {
        for(int j=1;j<=n*m-1;j++)
        {
            if(b[j]<b[j+1])
            {
                swap(b[j],b[j+1]);
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        if(b[i]==x)
        {
            printf("%d ",i/(n-1));
            if((i/n)%2==0)
            {
                printf("%d",n-(i%(n+1))+1);
                break;
            }
            else
            {
                printf("%d",i%(n+1)+2);
                break;
            }
        }
    }
    return 0;
}
