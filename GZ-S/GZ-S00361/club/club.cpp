//GZ-S00361 毕节东辰实验学校 罗圣喻
#include <bits/stdc++.h>
using namespace std;
struct node{
    long long num;
    int cnt,pos;
}a[300150];
int b[100050][3];
int vis[100050];
vector <int> q;
long long cmp(node x,node y)
{
    if(x.num == y.num)
    {
        if( b[ x.cnt ][1] ==b[ y.cnt ][1])
            return b[ x.cnt ][2]<b[ y.cnt ][2];
        return b[ x.cnt ][1]<b[ y.cnt ][1];
    }
    return x.num>y.num;
}
void read(long long &x)
{
    long long f=1;x=0;char c;c=getchar();
    while(c<'0' || c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
    x*=f;
}
long long f(int n)
{
    long long c[3];
    for(int i=1;i<=3*n;i++)
    {
            read( a[i].num );
            a[i].cnt=(i-1)/3+1;
            a[i].pos=i%3;
            if( a[i].pos == 1) c[0]=a[i].num;
            if( a[i].pos == 2) c[1]=a[i].num;
            if( a[i].pos == 0)
            {
                c[2]=a[i].num;
                sort(c,c+2);
                b[ a[i].cnt ][0]=c[2];
                b[ a[i].cnt ][1]=c[1];
                b[ a[i].cnt ][2]=c[0];
            }
    }
    sort(a+1,a+3*n,cmp);
    int x1,x2,x3;
    long long vol=0;
    x1=n/2,x2=n/2,x3=n/2;
    for(int i=1;i<=3*n;i++)
    {
        if( !vis[ a[i].cnt ] )
        {
            if( a[i].pos ==1)
            {
                if( x1 )
                {
                    vol+=a[i].num;
                    vis[ a[i].cnt ]=1;
                    x1--;
                }
            }
            else if( a[i].pos ==2)
            {
                if( x2 )
                {
                    vol+=a[i].num;
                    vis[ a[i].cnt ]=1;
                    x2--;
                }
            }
            else if( a[i].pos ==0)
            {
                if( x3 )
                {
                    vol+=a[i].num;
                    vis[ a[i].cnt ]=1;
                    x3--;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        vis[i]=0;
    }
    return vol;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long ans=f(n);
        printf("%ld\n",ans);
    }
    return 0;
}
