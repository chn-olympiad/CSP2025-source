#include<bits/stdc++.h>
using namespace std;
int n,m,t,s=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1,x;i<n*m;i++)
    {
        scanf("%d",&x);
        if(x>t)s++;
    }
    printf("%d ",(s-1)/n+1);
    if((s/n)%2==0)printf("%d",(s-1)%n+1);
    else printf("%d",n-(s-1)%n);
    return 0;
}
