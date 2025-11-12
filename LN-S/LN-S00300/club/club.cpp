#include<bits/stdc++.h>
using namespace std;
const int inf=2100000000;
int xx,yy,zz,ans,lef;
int bac[100005];
int fir[100005];
int cmp(int x,int y)
{
    return x<y;
}
int sol()
{
    memset(bac,0,sizeof(bac));
    memset(fir,0,sizeof(fir));
    ans=0;
    xx=0;
    yy=0;
    zz=0;
    lef=inf;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        int p=max(x,y);
        int q=max(p,z);
        if(q==x)
        {
            xx++;
            fir[i]=1;
            int r=max(y,z);
            bac[i]=x-r;
            ans+=x;
        }
        else if(q==y)
        {
            yy++;
            fir[i]=2;
            int r=max(x,z);
            bac[i]=y-r;
            ans+=y;
        }
        else if(q==z)
        {
            zz++;
            fir[i]=3;
            int r=max(x,y);
            bac[i]=z-r;
            ans+=z;
        }
    }
    int p=max(xx,yy);
    int q=max(p,zz);
    if(q<=(n/2))
    {
        printf("%d\n",ans);
    }
    else
    {
        vector<int> a;
        if(q==xx)
        {
            for(int i=1;i<=n;i++)
            {
                if(fir[i]==1)
                a.push_back(bac[i]);
            }
            sort(a.begin(),a.end(),cmp);
            int t=0;
            for(int i=0;i<(q-n/2);i++)
            {
                t+=a[i];
            }
            lef=min(lef,t);
        }
        else if(q==yy)
        {
            for(int i=1;i<=n;i++)
            {
                if(fir[i]==2)
                a.push_back(bac[i]);
            }
            sort(a.begin(),a.end(),cmp);
            int t=0;
            for(int i=0;i<(q-n/2);i++)
            {
                t+=a[i];
            }
            lef=min(lef,t);
        }
        else if(q==zz)
        {
            for(int i=1;i<=n;i++)
            {
                if(fir[i]==3)
                a.push_back(bac[i]);
            }
            sort(a.begin(),a.end(),cmp);
            int t=0;
            for(int i=0;i<(q-n/2);i++)
            {
                t+=a[i];
            }
            lef=min(lef,t);
        }
        printf("%d",ans-lef);
        printf("\n");
    }
    return 0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t)
    {
        t--;
        sol();
    }
    return 0;
}
