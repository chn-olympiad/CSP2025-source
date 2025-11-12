
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct mode
{
    int a,b,c,d;
    long long cha1,cha2,cha3;
}b[100005];
int t,a[100005][3],n,kl;//b[bianhao][zuidazhi-cidazhi,cidazhi-zuixiaozhi][zuidazhi-bianhao,cidazhi-bianhao,zuixiaozhi-bianhao]
pair<int,int> zuidazhi(int a,int b,int c)
{
    pair<int,int>d;
    if(a>=b)
    {
        if(b>=c)
        {

            d.first=0;
            d.second=1;
            return d;
        }
        else if(a>=c)
        {
            d.first=0,d.second=2;
            return d;
        }
        else
        {
            d.first=2,d.second=0;
            return d;
        }
    }
    else//b>a
    {
        if(a>c)
        {
            d.first=1,d.second=0;
            return d;
        }
        else if(c>b)
        {
            d.first=2,d.second=1;
            return d;
        }
        else
        {
            d.first=1,d.second=2;
            return d;
        }
    }
}
bool cmp1(mode a2,mode b)
{
    if(a2.cha1>b.cha1)
    return true;

    if(a2.cha1==b.cha1)

    return a[a2.a]>=a[b.a];
    return false;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    //ios:sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long x=0,y=0,z=0,cnt=1,ans=0;
        for(int i=1;i<=n;i++)
        {

            cin>>a[i][0]>>a[i][1]>>a[i][2];
            pair<int,int> op=zuidazhi(a[i][0],a[i][1],a[i][2]);
            b[i].a=op.first,b[i].b=op.second;
            if(op.first!=0&&op.second!=0)
            {
                b[i].c=0;
            }
            else if(op.first!=1&&op.second!=1)
            {
                b[i].c=1;
            }
            else
            {
                b[i].c=2;
            }
            b[i].cha1=a[i][b[i].a]-a[i][b[i].b];
            b[i].cha2=a[i][b[i].b]-a[i][b[i].c];
            b[i].cha3=a[i][b[i].a]-a[i][b[i].c];
            b[i].d=i;
        }
        sort(b+1,b+n+1,cmp1);
        int lp=-1;
        while(x<=n/2&&y<=n/2&&z<=n/2)
        {
            if(cnt==n+1)
                break;
            if(x==n/2&&b[cnt].a==0)
            {
                lp=0;break;
            }
            if(y==n/2&&b[cnt].a==1)
            {
                lp=1;break;
            }
            if(z==n/2&&b[cnt].a==2)
            {
                lp=2;break;
            }
            ans+=a[b[cnt].d][b[cnt].a];
            if(b[cnt].a==0)
                x++;
            if(b[cnt].a==1)
                y++;
            if(b[cnt].a==2)
                z++;
            //cout<<b[cnt].d<<' ';
            cnt++;
        }
        //cout<<lp;
        if(lp==-1)
        {
            if(t==0)
            cout<<ans;
            else
              cout<<ans<<endl;
            continue;
        }

        kl=lp;
        for(int i=cnt;i<=n;i++){
            if(b[i].a==lp)
            {
                //b[i].cha1=b[i].cha2;
                b[i].a=b[i].b;
                //cout<<b[i].a<<' ';
            }
            if(b[i].b==lp)
            {
                   //b[i].cha1=b[i].cha3;
                   b[i].b=b[i].c;
            }
        }
        //sort(b+cnt+1,b+n+1,cmp1);
        int l=n/2;
        while(l--)
        {
            ans+=a[b[cnt].d][b[cnt].a];
            cnt++;
        }
        if(t==0)
        cout<<ans;
        else
            cout<<ans<<endl;
    }
    return 0;
}
