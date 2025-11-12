#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n*m;++i)
    {
        scanf("%lld",&a[i]);
    }
    int score=a[1];
    sort(a+1,a+n*m+1,cmp);
    bool down=1;
    int h=1;
    int l=1;
    for(int i=1;i<=n*m;++i)
    {
        if(a[i]==score)
        {
            printf("%lld %lld",l,h);
            return 0;
        }
        if((l&1)&&!down)
        {
            down=1;
        }
        if((l&1)==0&&down)
        {
            down=0;
        }
        bool flag=1;
        if((l&1)&&h==n)
        {
            l++;
            flag=0;
        }
        if(!(l&1)&&h==1)
        {
            l++;
            flag=0;
        }
        if(down&&flag)
        {
            h++;
        }
        if(!down&&flag)
        {
            h--;
        }
    }
    return 0;
}
