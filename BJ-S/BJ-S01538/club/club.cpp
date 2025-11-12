#include<bits/stdc++.h>
#define mod 998244353
#define INF 1000000000
using namespace std;
const int maxn=1e5+5;
int t,n;
struct node{int x,y,z;}a[maxn];
int read()
{
    int u=0,v=1;
    char ch=getchar();
    while(ch<'0' || ch>'9')
    {
        if(ch=='-') v=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
    {
        u=(u<<3)+(u<<1)+(ch^48);
        ch=getchar();
    }
    return u*v;
}
void print(int x)
{
    if(x<0) x=-x,putchar('-');
    if(x<10) putchar(x+48);
    else print(x/10),putchar(x%10+48);
}
int minn(int a,int b,int c)
{
    if(a<=b && a<=c) return a;
    if(b<=a && b<=c) return b;
    return c;
}
int maxx(int a,int b,int c)
{
    if(a>=b && a>=c) return a;
    if(b>=a && b>=c) return b;
    return c;
}
bool cmp(node x,node y)
{
    int fx=maxx(x.x,x.y,x.z)-(x.x+x.y+x.z-minn(x.x,x.y,x.z)-maxx(x.x,x.y,x.z));
    int fy=maxx(y.x,y.y,y.z)-(y.x+y.y+y.z-maxx(y.x,y.y,y.z)-minn(y.x,y.y,y.z));
    return fx>fy;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        long long ans=0,cnt1=0,cnt2=0,cnt3=0;
        n=read();
        for(int i=1;i<=n;i++)
            a[i].x=read(),a[i].y=read(),a[i].z=read();
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            if(a[i].x>=a[i].y && a[i].x>=a[i].z)
            {
                if(cnt1<n/2)
                {
                    cnt1++;
                    ans+=a[i].x;
                }
                else if(a[i].y>=a[i].z)
                {
                    cnt2++;
                    ans+=a[i].y;
                }
                else
                {
                    cnt3++;
                    ans+=a[i].z;
                }
            }
            else if(a[i].y>=a[i].x && a[i].y>=a[i].z)
            {
                if(cnt2<n/2)
                {
                    cnt2++;
                    ans+=a[i].y;
                }
                else if(a[i].x>=a[i].z)
                {
                    cnt1++;
                    ans+=a[i].x;
                }
                else
                {
                    cnt3++;
                    ans+=a[i].z;
                }
            }
            else
            {
                if(cnt3<n/2)
                {
                    cnt3++;
                    ans+=a[i].z;
                }
                else if(a[i].x>=a[i].y)
                {
                    cnt1++;
                    ans+=a[i].x;
                }
                else
                {
                    cnt2++;
                    ans+=a[i].y;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
