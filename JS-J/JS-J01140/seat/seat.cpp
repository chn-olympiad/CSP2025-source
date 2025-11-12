#include<bits/stdc++.h>
using namespace std;

int a[100010];

bool cmp(int x , int y)
{
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n , m ;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n*m ; i++ )
    {
        scanf("%d",&a[i]);
    }
    int num = a[0];
    sort(a+1,a+n*m,cmp);
    int f = 0 ;
    int x = 1 , y = 1 ;
    int ans = -1 ;
    bool last = false;
    for(int i = 1 ; i < n*m ; i++ )
    {
        if(a[i] < num)
        {
            ans = 1;
            printf("%d %d",x,y);
            break;
        }
        if((y == 1 || y == n) && last == true)
        {
            x++;
            f = (f+1)%2;
            last = false;
            continue;
        }
        if(f == 1)
        {
            y--;
        }
        else{
            y++;
        }
        last = true;
    }
    if(ans == -1)
    {
        printf("%d %d",n,m);
    }
    return 0 ;
}
