#include<cstdio>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int a,x,h=0;
    scanf("%d",&a);
    for(int i=1;i<n*m;i++)
    {
        scanf("%d",&x);
        h+=(int)(x>a);
    }
    x=h/n;
    int y=(h+1)%n;
    y=(y==0)?(n):(y);
    if(x++%2)
    {
        y=n-y;
    }
    printf("%d %d",x,y);
    fclose(stdin);
    fclose(stdout);
    return 0;
}    
