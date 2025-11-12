/*
#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][4],b[4][50050],c[4][100005],nn,ans;
void clear()
{memset(a,0,sizeof(a));
 memset(b,0,sizeof(b));
 memset(c,0,sizeof(c));
 ans=-1;
}
void cal()
{for(int i=1;i<=n;i++)
    c[1][i]=c[2][i]=c[3][i]=i;
 for(int k=1;k<=3;k++)
    for(int i=n;i>1;i--)
       for(int j=n;j>n-i+1;j--)
          if(a[c[k][j]][k]>a[c[k][j-1]][k]) swap(c[k][j],c[k][j-1]);
 //cout<<"----------"<<endl;
 for(int k=1;k<=3;k++)
    for(int i=1;i<=nn;i++)
       for(int j=1;j<=i;j++)
          b[k][i]+=a[c[k][j]][k];
}
void tanxin()
{for(int k1=nn;k1>=0;k1--)
    {for(int k2=nn;k2>=0;k2--)
       {if(k1+k2>n) continue;
        int k3=n-k1-k2;
        printf("%d+%d+%d=%d\n",k1,k2,k3,b[1][k1]+b[2][k2]+b[3][k3]);
        ans=max(ans,b[1][k1]+b[2][k2]+b[3][k3]);
        }
     }
}
int main()
{freopen("club.in","r",stdin);
 //freoepn("club.out","w",stdout);
 scanf("%d",&T);
 for(int qq=1;qq<=T;qq++)
    {clear();
     scanf("%d",&n);
     nn=n/2;
     for(int i=1;i<=n;i++)
         scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
     //cout<<"---------a"<<endl;
     /*
     for(int i=1;i<=n;i++)
        {for(int j=1;j<=3;j++)
            printf("%d ",a[i][j]);
         printf("\n");
         }
     zhushi
     cal();
     //cout<<"---------c"<<endl;
     /*
     for(int i=1;i<=3;i++)
        {for(int j=1;j<=n;j++)
            printf("%d ",c[i][j]);
         printf("\n");
         }
     cout<<"---------b"<<endl;
     for(int i=1;i<=3;i++)
        {for(int j=1;j<=nn;j++)
            printf("%d ",b[i][j]);
         printf("\n");
         }
     zhushi
     tanxin();
     //cout<<"----------"<<endl;
     printf("%d\n",ans);
     }
return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],ans;
void clear()
{memset(a,0,sizeof(a));
 ans=0;
}
int main()
{freopen("club.in","r",stdin);
 freopen("club.out","w",stdout);
 scanf("%d",&t);
 for(int qq=1;qq<=t;qq++)
    {clear();
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
     if(n==2)
       {for(int i=1;i<=3;i++)
           for(int j=1;j<=3;j++)
              {if(i==j) continue;
               ans=max(ans,a[1][i]+a[2][j]);
               }
        printf("%d\n",ans);
        continue;
        }
     }
 return 0;
}
