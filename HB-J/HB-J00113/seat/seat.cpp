#include <iostream>
#include <algorithm>
using namespace  std;
int a[1001];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m*n;i++)
    {
        scanf("%d",&a[i]);
    }
    int b = a[0];
    sort(a,a+m*n,cmp);
    int c;
    for(int i = 0;i < m*n;i++)
    {
        if(b == a[i])
        {
            c = i+1;
            break;
        }
    }
    int line = 1;
    while(c > n)
    {
        c-=n;
        line++;
    }
    printf("%d ",line);
    if(line%2 != 0)
    {
        printf("%d",c);
    }
    else{
        printf("%d",n-c+1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
