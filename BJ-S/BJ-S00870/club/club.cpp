#include <bits/stdc++.h>
using namespace std;
int n;
long long z;
struct asd{
    int bm1,bm2,bm3;
    int f=0,r=0;
}a[20010];
struct asdf{
    int y[20010],sdf[20010],dfg[20010],sum,xb=1;
}bm[10];
void fp(int my1,int my2,int my3)
{
    if (my1>=my2&&my1>=my3)
    {

        if (bm[1].sum<n/2)
        {
            bm[1].sum++;
            bm[1].y[bm[1].xb]=my1;
            bm[1].sdf[bm[1].xb]=my2;
            bm[1].dfg[bm[1].xb]=my3;
            bm[1].xb++;
            z+=my1;
        }
        else
        {
            for (int i=1;i<=bm[1].xb;i++)
            {
                if (bm[1].y[i]<my1)
                {
                    z-=bm[1].y[i];
                    z+=my1;
                    int zxc,xcv,cvb;
                    zxc=bm[1].y[i];
                    xcv=bm[1].sdf[i];
                    cvb=bm[1].dfg[i];
                    fp(zxc,xcv,cvb);
                }
            }
        }
    }
    else if(my2>=my1&&my2>=my3)
    {

        if (bm[2].sum<n/2)
        {
            bm[2].sum++;
            bm[2].y[bm[2].xb]=my1;
            bm[2].sdf[bm[2].xb]=my2;
            bm[2].dfg[bm[2].xb]=my3;
            bm[2].xb++;
            z+=my1;
        }
        else
        {
            for (int i=1;i<=bm[2].xb;i++)
            {
                if (bm[2].y[i]<my1)
                {
                    z-=bm[2].y[i];
                    z+=my2;
                    int zxc,xcv,cvb;
                    zxc=bm[2].y[i];
                    xcv=bm[2].sdf[i];
                    cvb=bm[2].dfg[i];
                    fp(zxc,xcv,cvb);
                }
            }
        }
    }
    else{
        if (bm[3].sum<n/2)
        {
            bm[3].sum++;
            bm[3].y[bm[3].xb]=my1;
            bm[3].sdf[bm[3].xb]=my2;
            bm[3].dfg[bm[3].xb]=my3;
            bm[3].xb++;
            z+=my1;
        }
        else
        {
            for (int i=1;i<=bm[3].xb;i++)
            {
                if (bm[3].y[i]<my1)
                {
                    z-=bm[3].y[i];
                    z+=my3;
                    int zxc,xcv,cvb;
                    zxc=bm[3].y[i];
                    xcv=bm[3].sdf[i];
                    cvb=bm[3].dfg[i];
                    fp(zxc,xcv,cvb);
                }
            }
        }
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        n=0;
        z=0;
        cin >> n;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i].bm1>>a[i].bm2>>a[i].bm3;
            fp(a[i].bm1,a[i].bm2,a[i].bm3);
        }
        cout << z << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}