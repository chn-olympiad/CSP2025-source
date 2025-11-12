#include <bits/stdc++.h>
using namespace std;
int n,m,f[100001][5],t[100001],y,x,ans,ans1,a,b,c;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        x=m/2;
        t[0]=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&f[i][1],&f[i][2],&f[i][3]);
            if(i<=x)
                t[i]=1;
            else
                t[i]=2;
        }
        a=x,b=x,c=0;
        while(t[0]!=1)
        {
            y=m;
            t[m]++;
            if(t[m]==2)
                a--,b++;
            else if(t[m]==3)
                b--,c++;
            else while(t[y]==4)
            {
                t[y]=1,y--,t[y]++;
                a++,c--;
                if(t[y]==2)
                    a--,b++;
                if(t[y]==3)
                    b--,c++;
            }
            if(a<=x&&b<=x&&c<=x)
            {
                if(t[0]==1)
                    break;
                for(int i=1;i<=m;i++)
                {
                    ans1+=f[i][t[i]];
                }
            }
            ans=max(ans,ans1);
            ans1=0;
        }
        printf("%d\n",ans);
        ans=0;
    }
    return 0;
}
