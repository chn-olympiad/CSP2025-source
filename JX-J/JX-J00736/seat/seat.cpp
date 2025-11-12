#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){return a>b;}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    int s[n*m+1],a[n+1][m+1];
    for(int i=1;i<=n*m;i++)
        scanf("%d",&s[i]);
    int r=s[1],t=0;
    sort(s+1,s+1+n*m,cmp);
    for(int j=1;j<=m;j++)
    {
        if(j%2==1)
        {
        for(int i=1;i<=n;i++)
        {t++;a[i][j]=s[t];}
        }
        if(j%2==0)
        {
        for(int i=n;i>=1;i--)
        {
        t++;a[i][j]=s[t];
        }
        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        if(r==a[i][j]) {printf("%d %d",j,i);
        i=n;j=m;
        }
        }
    fclose(stdin);fclose(stdout);
    return 0;
}
