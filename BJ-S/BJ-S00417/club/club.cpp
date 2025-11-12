#include <bits/stdc++.h>
using namespace std;

int t,n;
int a[100005],b[100005],c[100005];
int cmp(int a,int b)
{
    if(a>b)return a>b;
    else return b>a;
}
void club(int n,int a[],int b[],int c[])
{
    int ans=0,anum=0,bnum=0,cnum=0;
    n=n/2;
    for(int i=1;i<=n;i++)
    {
        int maxn=max(a[i],b[i]);
        maxn=max(maxn,c[i]);
        if(maxn==a[i])
        {
            if(anum<=n)
            {
                anum++;
                ans+=maxn;
            }
            else
            {
                if(b[i]>c[i])
                {
                    bnum++;
                    ans+=b[i];
                }
                else
                {
                    cnum++;
                    ans+=c[i];
                }
            }
        }
        if(maxn==b[i])
        {
            if(cnum<=n)
            {
                bnum++;
                ans+=maxn;
            }
            else
            {
                if(a[i]>c[i])
                {
                    anum++;
                    ans+=a[i];
                }
                else
                {
                    cnum++;
                    ans+=c[i];
                }
            }
        }
        if(maxn==c[i])
        {
            if(cnum<=n)
            {
                cnum++;
                ans+=maxn;
            }
            else
            {
                if(a[i]>b[i])
                {
                    anum++;
                    ans+=a[i];
                }
                else
                {
                    bnum++;
                    ans+=b[i];
                }
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        club(n,a,b,c);
    }
    return 0;
}
