#include<bits/stdc++.h>
using namespace std;
struct P{
    int v1,club1,v2,club2,v3,club3;
}al[100000+5],bl[100000+5];
int t,n;
long long ans;
bool cmp(P a,P b)
{
    if(a.v1!=b.v1) return a.v1>a.v1;
    if(a.v2!=b.v2) return a.v2>b.v2;
    return a.v3>b.v3;
}
void cinf(int j,int a,int b,int c)
{
    if(a>=b&&b>=c)
    {
        al[j].v1=a; al[j].club1=1;
        al[j].v2=b; al[j].club2=2;
        al[j].v3=c; al[j].club3=3;
    }else if(a>=c&&c>=b)
    {
        al[j].v1=a; al[j].club1=1;
        al[j].v2=c; al[j].club2=3;
        al[j].v3=b; al[j].club3=2;
    }else if(b>=a&&a>=c)
    {
        al[j].v1=b; al[j].club1=2;
        al[j].v2=a; al[j].club2=1;
        al[j].v3=c; al[j].club3=3;
    }else if(b>=c&&c>=a)
    {
        al[j].v1=b; al[j].club1=2;
        al[j].v2=c; al[j].club2=3;
        al[j].v3=a; al[j].club3=1;
    }else if(c>=a&&a>=b)
    {
        al[j].v1=c; al[j].club1=3;
        al[j].v2=a; al[j].club2=1;
        al[j].v3=b; al[j].club3=2;
    }else
    {
        al[j].v1=c; al[j].club1=3;
        al[j].v2=b; al[j].club2=2;
        al[j].v3=a; al[j].club3=1;
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;ans=0;
        int f[4]={0,n/2,n/2,n/2},fx=0;
        int a=0,b=0,c=0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d %d %d",&a,&b,&c);
            cinf(j,a,b,c);
        }
        sort(al+1,al+n+1,cmp);

        int je=0;
        for(int j=1;j<=n;j++)
        {
            if(f[al[j].club1]>0)
            {
                ans+=al[j].v1;
                f[al[j].club1]--;
            }
            if(f[al[j].club1]==0)
            {
                je=j+1;fx=1;
                break;
            }
        }
        if(fx)
        {
            for(int j=je;j<=n;j++)
            {
                if(f[al[j].club1]==0)
                {
                    bl[j].v1=al[j].v2; bl[j].club1=al[j].club2;
                    bl[j].v2=al[j].v3; bl[j].club2=al[j].club3;
                    bl[j].v3=0; bl[j].club2=al[j].club1;
                }
                else bl[j]=al[j];
            }

            sort(bl+je,bl+n+1,cmp);
            for(int j=je;j<=n;j++) ans+=bl[j].v1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

