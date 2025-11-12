#include <bits/stdc++.h>
using namespace std;
int qw[10000001],we[100000001];
int main()
{
    int a,s,d,q;
    scanf("%d %d %d",&a,&s,&d);
    int f=d;
    for(int i=2;i<=a*s;i++)
    {
        scanf("%d",&q);
    }
    f=100-f;
    int g=f;
    f=f/a+1;
    printf("%d ",f);
    if(f%2==1)
    {
        g=(100-g)%a+1;
        printf("%d",g);
    }
    else
    {
        g=a-((101-g)-(f-1)*a);
        printf("%d",g);
    }
}
