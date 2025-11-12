#include <bits/stdc++.h>
using namespace std;

int t,n,ans,a[100005][5],f[100005],bm[5];//1<=t<=5,a[100005][5]

bool cmp(int x,int y)
{
    return x<y;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        for(int i=1;i<=n;++i)
                f[i]=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            //int s1,s2,s3;
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            //sort(a[i]+1,a[i]+4,cmp);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=3;++j)
            {
                if(f[i]>=f[i-1]+a[i][j])
                    f[i]=f[i];
                else
                {
                    if(bm[j]<n/2)
                    {
                        f[i]=f[i-1]+a[i][j];
                        bm[j]+=1;
                    }
                }
            }
        }

        bm[1]=0;
        bm[2]=0;
        bm[3]=0;

        printf("%d\n",f[n]);
    }
    return 0;
}
/*
for(int i=1;i<=n;++i)
        {
            printf("i:%d\n",i);
            for(int k=1;k<=3;++k)
            {
                printf("k:%d\n",k);
                for(int j=1;j<=3;++j)
                {
                    printf("j:%d\n",j);
                    if(f[i][j]>f[i-1][j]+a[i][k])
                    {
                        f[i][j]=f[i][j];
                        printf("f[%d][%d]=%d NO\n",i,j,f[i][j]);
                    }
                    else
                    {
                        if(bm[k]<n/2)
                        {
                            f[i][j]=f[i-1][j]+a[i][k];
                            bm[k]+=1;
                            printf("f[%d][%d]=%d YES\n",i,j,f[i][j]);
                        }
                    }
                }
            }
        }*/
