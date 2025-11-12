#include<bits/stdc++.h>
using namespace std;
int a[50][50],n,m;
int c[1000],lenc=1,k;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            c[lenc]=a[i][j];
            lenc++;
        }
    }
    lenc-=1;
    sort(c+1,c+1+lenc,cmp);
    for(int i=1;i<=lenc;i++)
    {
        if(c[i]==a[1][1])
        {
            k=a[1][1];
            break;
        }
    }
    lenc=1;
    int ju=0;
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=n;j++)
            {

                a[j][i]=c[lenc];
                //cout<<a[j][i]<<"!!1"<<' '<<i<<j<<endl;
                lenc++;
                if(c[lenc-1]==k)
                {
                    printf("%d %d",i,j);
                    ju=1;
                    break;
                }
            }
        }
        if(i%2==0)
        {
            for(int j=n;j>=1;j--)
            {

                a[j][i]=c[lenc];
                lenc++;
                if(c[lenc-1]==k)
                {
                    printf("%d %d",i,j);
                    ju=1;
                    break;
                }
                //cout<<a[j][i]<<"!!1"<<' '<<i<<j<<endl;
            }
        }
        if(ju)
        {
            break;
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    */
    return 0;
}
