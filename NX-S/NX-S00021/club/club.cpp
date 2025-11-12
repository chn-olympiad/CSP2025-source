#include<bits/stdc++.h>
using namespace std;
int n,t,p,t1,t2,t3,ansend;
int a[10100][5];
int c[10000][5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        p=n/2;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j][1]>>a[j][2]>>a[j][3];
            if(a[j][1]>a[j][2])
            {
                if(a[j][1]>a[j][3]) c[j][1]=a[j][1];
                else c[j][3]=a[j][3];
            }
            else
            {
                if(a[j][2]>a[j][3]) c[j][2]=a[j][2];
                else c[j][3]=a[j][3];
            }
            for(int k=1;k<=j;k++)
            {
                if(c[j][1]>t1&&a[j][4]==0)
                {
                    t1=c[j][1];
                    zj1=j;
                }
                if(c[j][2]>t2&&a[j][4]==0)
                {
                    t2=c[j][2];
                    zj2=j;
                }if(c[j][3]>t3&&a[j][4]==0)
                {
                    t1=c[j][3];
                    zj3=j;
                }
            }
            if(b[1]<p) ansend+=t1,b[1]++;
            else a[zj1][1]=0;
            if(b[2]<p) ansend+=t2,b[2]++;
            else a[zj2][2]=0;
            if(b[3]<p) ansend+=t2,b[3]++;
            if(t1!=0) a[zj1][4]=1;
            if(t2!=0) a[zj2][4]=1;
            if(t3!=0) a[zj3][4]=1;
        }
        cout<<endl<<ansend;
    }
    return 0;
}
