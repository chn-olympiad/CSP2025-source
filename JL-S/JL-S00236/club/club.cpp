#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Edge
{
    int x,y;
}k[N];
struct Node
{
    int s,w;
}a[N][3];
bool cmp(Node x,Node y)
{
    return x.s<y.s;
}
bool cmp1(Edge x,Edge y)
{
    return x.x>y.x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while (T--)
    {
        memset(k,0,sizeof k);
        int n,ans=0;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=3;j++)
            {
                cin>>a[i][j].s;
                a[i][j].w=j;
            }
            sort(a[i]+1,a[i]+4,cmp);
        }
        int cnt1=0,cnt2=0,cnt3=0;
        for (int i=1;i<=n;i++)
        {
            if (a[i][3].w==1) cnt1++;
            else if (a[i][3].w==2)  cnt2++;
            else cnt3++;
        }
        if (cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2)
        {
            for (int i=1;i<=n;i++)ans+=a[i][3].s;
            cout<<ans<<endl;
            continue;
        }
        int cntk=0;
        if (cnt1>n/2)
        {
            for (int i=1;i<=n;i++)
                if (a[i][3].w!=1) ans+=a[i][3].s;
            for (int i=1;i<=n;i++)
                if (a[i][3].w==1)
                {
                    k[++cntk].x=a[i][3].s-a[i][2].s;
                    k[cntk].y=i;
                }
        }
        if (cnt2>n/2)
        {
            for (int i=1;i<=n;i++)
                if (a[i][3].w!=2) ans+=a[i][3].s;
            for (int i=1;i<=n;i++)
                if (a[i][3].w==2)
                {
                    k[++cntk].x=a[i][3].s-a[i][2].s;
                    k[cntk].y=i;
                }
        }
        if (cnt3>n/2)
        {
            for (int i=1;i<=n;i++)
                if (a[i][3].w!=3) ans+=a[i][3].s;
            for (int i=1;i<=n;i++)
                if (a[i][3].w==3)
                {
                    k[++cntk].x=a[i][3].s-a[i][2].s;
                    k[cntk].y=i;
                }
        }
        sort(k+1,k+cntk+1,cmp1);
        for (int i=1;i<=n/2;i++) ans+=a[k[i].y][3].s;
        for (int i=n/2+1;i<=cntk;i++)   ans+=a[k[i].y][2].s;
        cout<<ans<<'\n';
    }
}
