#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,t,ans,b[5],xl,yl,kl,sum;
struct data
{
    ll d[5],max1[5],wz[5];
} a[N];
ll mmax(ll kx,ll ky)
{
    if(kx>=ky) return kx;
    else return ky;
}
void fuzhi(ll ax,ll num,ll k)
{
    a[ax].max1[k]=a[ax].d[num];
    a[ax].wz[k]=num;
}
void work(ll x)// how max wz x=a[i];
{
    if(a[x].d[1]==mmax(a[x].d[1],mmax(a[x].d[2],a[x].d[3])))
    {
        fuzhi(x,1,1);
        if(a[x].d[2]==mmax(a[x].d[2],a[x].d[3])) fuzhi(x,2,2);
        else fuzhi(x,3,2);
    }
    else if(a[x].d[2]==mmax(a[x].d[1],mmax(a[x].d[2],a[x].d[3])))
    {
        fuzhi(x,2,1);
        if(a[x].d[1]==mmax(a[x].d[1],a[x].d[3])) fuzhi(x,1,2);
        else fuzhi(x,3,2);
    }
    else
    {
        fuzhi(x,3,1);
        if(a[x].d[2]==mmax(a[x].d[2],a[x].d[1])) fuzhi(x,2,2);
        else fuzhi(x,1,2);
    }
}
bool cmp(data l,data l1)
{
    if(l.max1[1]>l1.max1[1]) return true;
    else if(l.max1[1]==l1.max1[1])
    {
        if(l.max1[2]>l1.max1[2]) return true;
        else if(l.max1[2]==l1.max1[2])
        {
            if(l.d[6-l.wz[1]-l.wz[2]]>=l1.d[6-l1.wz[1]-l1.wz[2]]) return true;
        }
    }
    return false;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        sum=0;
        memset(a,0,sizeof(a));
        ans=0;
        memset(b,0,sizeof(b));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
            if(a[i].d[2]==a[i].d[3]==0) sum++;
            work(i);
        }
        kl=n>>1;
        sort(a+1,a+n+1,cmp);
        if(sum==n)
        {
            for(int i=1;i<=kl;i++) ans+=a[i].d[1];
            cout<<ans;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(b[a[i].wz[1]]+1==kl&&a[i].wz[1]==a[i+1].wz[1])//full
                {
                    xl=a[i].max1[1]+a[i+1].max1[2];
                    yl=a[i].max1[2]+a[i+1].max1[1];
                    if(xl>=yl)
                    {
                        ans+=xl;
                        b[a[i].wz[1]]+=1;
                        b[a[i+1].wz[2]]+=1;
                    }
                    else
                    {
                        ans+=yl;
                        b[a[i].wz[2]]+=1;
                        b[a[i+1].wz[1]]+=1;
                    }
                    i++;
                }
                else if(b[a[i].wz[1]]+1<=kl)
                {
                    ans+=a[i].max1[1];
                    b[a[i].wz[1]]+=1;
                }
                else
                {
                    ans+=a[i].max1[2];
                    b[a[i].wz[2]]+=1;
                }
            //cout<<ans<<" ";
            }
            cout<<ans<<'\n';
        }
        //cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" ";
    }
    return 0;
}
