#include"stdio.h"
#include<algorithm>
#define N 15

int n,m,a[N*N];
int seat[N][N] = {0};

bool cmp(int x,int y)
{
    return x > y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n*m;i++) scanf("%d",&a[i]);
    int s = a[0];
    std::sort(a,a + n*m,cmp);
    int x = 1,y = 1;
    for(int i=0;i<n*m;i++)
    {
        seat[x][y] = a[i];
        if(a[i] == s)
        {
            printf("%d %d",y,x);
            break;
        }
        if((x==n && y%2) || (x==1 && y%2==0))
            y ++;
        else
        {
            if(y % 2) x ++;
            else x --;
        }
    }
    return 0;
}
