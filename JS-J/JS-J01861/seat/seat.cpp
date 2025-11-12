#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
        x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}
void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar('0'+x%10);
}
const int N=105;
int n,m,a[N],x;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n*m;i++)
        a[i]=read();
    x=a[1];
    sort(a+1,a+n*m+1);
    int cur=n*m+1;
    for(int i=1;i<=m;i++)
    {
        if(i&1)
        {
            for(int j=1;j<=n;j++)
            {
                cur--;
                if(a[cur]==x)
                {
                    write(i),putchar(' '),write(j);
                    return 0;
                }
            }
        }
        else
        {
            for(int j=n;j;j--)
            {
                cur--;
                if(a[cur]==x)
                {
                    write(i),putchar(' '),write(j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
