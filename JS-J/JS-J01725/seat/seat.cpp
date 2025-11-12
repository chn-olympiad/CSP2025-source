#include<bits/stdc++.h>
#define N 15
using namespace std;
int n,m,a[N][N],b[N*N],k,temp;
bool f;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&b[i]);
    temp=b[1];
    sort(b+1,b+n*m+1,greater<int>());
    for(int i=1;i<=m;i++)
    {
        if(f==0)
        {
            for(int j=1;j<=n;j++)
            {
                a[j][i]=b[++k];
                if(b[k]==temp)
                {
                    printf("%d %d",i,j);
                    return 0;
                }
            }
            f=1;
        }
        else if(f==1)
        {
            for(int j=n;j>=1;j--)
            {
                a[j][i]=b[++k];
                if(b[k]==temp)
                {
                    printf("%d %d",i,j);
                    return 0;
                }
            }
            f=0;
        }
    }
    return 0;
}
