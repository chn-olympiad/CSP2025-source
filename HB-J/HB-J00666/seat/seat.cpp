#include<bits/stdc++.h>
using namespace std;
int a[10005];
bool cmp(int X,int Y)
{
    return X>Y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int R;
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    R=a[1];
    sort(a+1,a+1+(n*m),cmp);
    int x=1,y=1;
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==R)
        {
            printf("%d %d",x,y);
            return 0;
        }
        if((x&1)==1)
        {
            if(y==n)
            {
                x++;
            }
            else
            {
                y++;
            }
        }
        else
        {
            if(y==1)
            {
                x++;
            }
            else
            {
                y--;
            }
        }
    }
    return 0;
}
