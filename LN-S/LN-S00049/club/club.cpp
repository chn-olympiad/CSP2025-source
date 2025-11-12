#include <bits/stdc++.h>
using namespace std;
struct book
{
    int x,y,z;
};
book a[100010];
int t,n;
bool abc (book x,book y)
{
    int aa[5],bb[5];
    aa[1]=x.x;
    aa[2]=x.y;
    aa[3]=x.z;
    bb[1]=y.x;
    bb[2]=y.y;
    bb[3]=y.z;
    sort (aa+1,aa+4);
    sort (bb+1,bb+4);
    return (aa[3]-aa[2])>(bb[3]-bb[2]);
}
int main ()
{
    freopen ("club.in","r",stdin);
    freopen ("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
        }
        sort (a+1,a+1+n,abc);
        int cnta=0,cntb=0,cntc=0;
        long long he=0;
        for (int i=1;i<=n;i++)
        {
            int ttd=max (a[i].x,max (a[i].y,a[i].z)),ttx=min (a[i].x,min (a[i].y,a[i].z));
            if (a[i].x==ttd)
            {
                if (cnta<n/2)
                {
                    he=he+a[i].x;
                    cnta++;
                }
                else
                {
                    if (a[i].y!=ttx)
                    {
                        he=he+a[i].y;
                        cntb++;
                    }
                    else
                    {
                        he=he+a[i].z;
                        cntc++;
                    }
                }
            }
            else if (a[i].y==ttd)
            {
                if (cntb<n/2)
                {
                    he=he+a[i].y;
                    cntb++;
                }
                else
                {
                    if (a[i].x!=ttx)
                    {
                        he=he+a[i].x;
                        cnta++;
                    }
                    else
                    {
                        he=he+a[i].z;
                        cntc++;
                    }
                }
            }
            else if (a[i].z==ttd)
            {
                if (cntc<n/2)
                {
                    he=he+a[i].z;
                    cntc++;
                }
                else
                {
                    if (a[i].x!=ttx)
                    {
                        he=he+a[i].x;
                        cnta++;
                    }
                    else
                    {
                        he=he+a[i].y;
                        cntb++;
                    }
                }
            }
        }
        cout<<he<<endl;
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}//?qwq
