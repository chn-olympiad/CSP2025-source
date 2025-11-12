#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int t;
bool b[N];
struct www
{
    int x,id;
}bx[N],cx[N];
struct ww
{
    int x,id,sd;
}xx[N];
bool cmp(www A,www B)
{
    return A.x>B.x;
}
int main()
{
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        memset(b,false,sizeof(b));
        int n,ans=0;
        cin>>n;
        bool bb=true;
        for (int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if (c!=0)bb=false;
            bx[i]={b-a,i};
            cx[i]={c-a,i};
            ans+=a;
        }
        if (bb)
        {
            sort(bx+1,bx+n+1,cmp);
            for (int i=1;i<=n/2;i++)
                if (bx[i].x>0)
                    ans+=bx[i].x;

            cout<<ans<<endl;
            continue;
        }
        sort(bx+1,bx+n+1,cmp);
        sort(cx+1,cx+n+1,cmp);
        int i=1,j=1,cna=0,cnb=0,k=n/2;
        while (cna+cnb!=k)
        {
            if (i<=n&&j<=n&&bx[i].x>=cx[j].x)
            {
                if (!b[bx[i].id])
                {
                    ans+=bx[i].x;
                    b[bx[i].id]=true;
                    cna++;
                }
                i++;
            }
            else if (i<=n&&j<=n&&bx[i].x<cx[j].x)
            {
                if (!b[cx[j].id])
                {
                    ans+=cx[j].x;
                    b[cx[j].id]=true;
                    cnb++;
                }
                j++;
            }
        }

        int f=0;
        while (i<=n&&j<=n)
        {
            if (bx[i].x>=cx[j].x)
            {
                f++;
                xx[f]={bx[i].x,bx[i].id,1};
                i++;
            }
            else
            {
                f++;
                xx[f]={cx[i].x,cx[i].id,2};
                j++;
            }
        }
        while (i<=n)
        {
            f++;
            xx[f]={bx[i].x,bx[i].id,1};
            i++;
        }
        while (j<=n)
        {
            f++;
            xx[f]={cx[i].x,cx[i].id,2};
            j++;
        }
        for (int i=1;i<=f;i++)
        {
            if (b[xx[i].id])continue;
            if (xx[i].sd==1&&cna!=n/2&&xx[i].x>0)
            {
                cna++;
                ans+=xx[i].x;
            }
            if (xx[i].sd==2&&cnb!=n/2&&xx[i].x>0)
            {
                cnb++;
                ans+=xx[i].x;
            }
            b[xx[i].id]=true;
        }
        cout<<ans<<endl;
    }
    return 0;
}
