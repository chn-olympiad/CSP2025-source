#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k,p=0;
int a[N];
int f[N][21];
int s[21][N];
int g[21];
struct www
{
    int l,r;
}ans[N*2];
bool cmp(www A,www B)
{
    if (A.r==B.r)return A.l<B.l;
    return A.r<B.r;
}
int main()
{
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)cin>>a[i];
    bool b=true;
    for (int i=1;i<=n&&b;i++)
        if (a[i]!=1)
            b=false;
    if (b&&k==0)
    {
        cout<<n/2<<endl;
        return 0;
    }
    b=true;
    for (int i=1;i<=n&&b;i++)
        if (a[i]!=1&&a[i]!=0)
            b=false;
    if (b)
    {
        int res=0;
        for (int i=1;i<=n;i++)
            if (a[i]==0)
                res++;
        if (k==0)cout<<res<<endl;
        if (k==1)cout<<n-res<<endl;
        return 0;
    }




    memset(s,0,sizeof(s));
    for (int i=1;i<=n;i++)
    {
        int x=a[i],h=0;
        while (x!=0)
        {
            h++;
            f[i][h]=(x&1);
            x/=2;
        }
        for (int j=h+1;j<=20;j++)f[i][j]=0;
    }
    for (int i=1;i<=20;i++)
        for (int j=1;j<=n;j++)
            s[i][j]=s[i][j-1]+f[j][i];

    int d=k,h=0;
    while (d!=0)
    {
        h++;
        g[h]=(d&1);
        d/=2;
    }
    for (int j=h+1;j<=20;j++)g[j]=0;


    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
        {
            bool b=true;
            for (int o=1;o<=20&&b;o++)
                if ((s[o][j]-s[o][i-1])%2!=g[o]%2)
                    b=false;
            if (b)
            {
                p++;
                ans[p].l=i;ans[p].r=j;
            }
        }
    int st=-1,cnt=0;
    sort(ans+1,ans+p+1,cmp);
    for (int i=1;i<=p;i++)
    {
        if (ans[i].l>st)
        {
            st=ans[i].r;
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
