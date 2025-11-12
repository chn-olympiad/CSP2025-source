#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n;
int sum1;
int sum2;
int sum3;
int bm1,bm2,bm3;
struct m
{
    int a1,a2,a3;
    double x1,x2,x3,xz;
    int bm;
}a[100010];
bool cmp(m x,m y) {
    return x.xz<=y.xz;}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    for (int w=1;w<=t;w++)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            sum1=0;
            sum2=0;
            sum3=0;
            cin>>a[i].a1;
            cin>>a[i].a2;
            cin>>a[i].a3;
            if (a[i].a1==0)
            {
                a[i].a1=-1;
            }
            if (a[i].a2==0)
            {
                a[i].a2=-1;
            }
            if (a[i].a3==0)
            {
                a[i].a3=-1;
            }
            sum1+=a[i].a1;
            sum2+=a[i].a2;
            sum3+=a[i].a3;
        }
        for (int i=1;i<=n;i++)
        {
            a[i].x1=a[i].a1/sum1*1.0;
            a[i].x2=a[i].a2/sum2*1.0;
            a[i].x3=a[i].a3/sum3*1.0;
            double temp=0x3f3f3f3f;
            if (a[i].x1>=0)
            {
                temp=min(temp,a[i].x1);
            }
            if (a[i].x2>=0)
            {
                temp=min(temp,a[i].x2);
            }
            if (a[i].x3>=0)
            {
                temp=min(temp,a[i].x3);
            }
            a[i].xz=temp;
            if (a[i].xz==a[i].x1)
            {
                a[i].bm=1;
            }
            else if (a[i].xz==a[i].x2)
            {
                a[i].bm=2;
            }
            else if (a[i].xz==a[i].x3)
            {
                a[i].bm=3;
            }
        }
        sort(a+1,a+n+1,cmp);
        int ans=0;
        int h=1;
        for (int i=1;i<=n;i++)
        {
            if (a[h].bm==1&&bm1<(n/2))
            {
                ans+=a[h].a1;
                bm1++;
            }
            else if (a[h].bm==2&&bm2<(n/2))
            {
                ans+=a[h].a2;
                bm2++;
            }
            else if (a[h].bm==3&&bm3<(n/2))
            {
                ans+=a[h].a3;
                bm3++;
            }
            h++;
        }
        cout<<ans<<endl;
    }
    return 0;
}