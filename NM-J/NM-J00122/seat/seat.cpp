#include<bits/stdc++.h>
using namespace std;
int n,m,a[102],qkhm,kid;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]);
    qkhm=a[1];
    kid=1;
    sort(a+1,a+n*m+1,greater<int>());
    for(int j=1;j<=m;j+=2)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[kid]==qkhm)
            {
                printf("%d %d",j,i);
                return 0;
            }
            kid++;
        }
        for(int i=n;i>=1;i--)
        {
            if(a[kid]==qkhm)
            {
                printf("%d %d",j+1,i);
                return 0;
            }
            kid++;
        }
    }
    if(m&1)
        for(int i=1;i<=n;i++)
        {
            if(a[kid]==qkhm)
            {
                printf("%d %d",m,i);
                return 0;
            }
            kid++;
        }
    return 0;
}
