#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int tmp=n*m+1;
    int a[tmp];
    for(int i=1;i<=m*n;i++)
    {
        cin>>a[i];
    }
    int temp=a[1];
    sort(a,a+tmp+1,cmp);
    int mc;
    for(int i=1;i<=m*n;i++)
    {
        if(a[i]==temp)
        {
            mc=i;
            break;
        }
    }
    int c=1,r=1;
    for(c=1;c<=n;c++)
    {
        for(r=1;r<=m;r++)
        {
            if(c%2)
            {
                if((c-1)*n+r==mc)
                {
                    cout<<c<<' '<<r;
                    return 0;
                }
            }
            else
            {
                if((c-1)*n+r-m+1==mc)
                {
                    cout<<c<<' '<<r;
                    return 0;
                }
            }
        }
    }
    return 0;
}
