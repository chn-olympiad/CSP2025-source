#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,a[N],b[N],c[N],g[N],n;
int g1[N],g2[N],g3[N];
struct node
{
    int id,w;
}d[N],e[N],f[N];
bool cmp(int a,int b)
{
    return a>b;
};
bool checkA(int b[],int c[])
{
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(b[i]!=0||c[i]!=0) flag=false;
    }
    return flag;
}
bool checkB(int c[])
{
    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=0) flag=false;
    }
    return flag;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        long long ans=0;
        int cnt1=0,cnt2=0,cnt3=0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
        memset(e,0,sizeof e);
        memset(f,0,sizeof f);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            d[i].w=max(a[i],max(b[i],c[i]));
            f[i].w=min(a[i],min(b[i],c[i]));
            if(d[i].w==a[i])
            {
                d[i].id=1;
                if(f[i].w==b[i])
                {
                    f[i].id=2;
                    e[i].w=c[i];
                    e[i].id=3;
                }
                if(f[i].w==c[i])
                {
                    f[i].id=3;
                    e[i].w=b[i];
                    e[i].id=2;
                }
            }
            if(d[i].w==b[i])
            {
                d[i].id=2;
                if(f[i].w==a[i])
                {
                    f[i].id=1;
                    e[i].w=c[i];
                    e[i].id=3;
                }
                if(f[i].w==c[i])
                {
                    f[i].id=3;
                    e[i].w=a[i];
                    e[i].id=1;
                }
            }
            if(d[i].w==c[i])
            {
                d[i].id=3;
                if(f[i].w==b[i])
                {
                    f[i].id=2;
                    e[i].w=a[i];
                    e[i].id=1;
                }
                if(f[i].w==a[i])
                {
                    f[i].id=1;
                    e[i].w=b[i];
                    e[i].id=2;
                }
            }
            g[i]=d[i].w-e[i].w;
            //cout<<"check:"<<d[i].w<<" "<<e[i].w<<" "<<f[i].w<<" "<<g[i]<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            ans+=d[i].w;
            if(d[i].id==1)
            {
                cnt1++;
                g1[cnt1]=i;
            }
            else if(d[i].id==2)
            {
                cnt2++;
                g2[cnt2]=i;
            }
            else
            {
                cnt3++;
                g3[cnt3]=i;
            }
        }
    /*
        for(int i=1;i<=cnt1;i++) cout<<g1[i]<<" "<<g[g1[i]]<<" "<<endl;
        cout<<"over1"<<endl;
        for(int i=1;i<=cnt2;i++) cout<<g2[i]<<" "<<g[g2[i]]<<" "<<endl;
        cout<<"over2"<<endl;
        for(int i=1;i<=cnt3;i++) cout<<g3[i]<<" "<<g[g3[i]]<<" "<<endl;
        cout<<"over3"<<endl;
    */
        if(max(cnt1,max(cnt2,cnt3))<=n/2)
        {
            cout<<ans<<endl;
            continue;
        }
        else
        {
            if(cnt1>n/2)
            {
                for(int i=1;i<=cnt1;i++)
                {
                    for(int j=i+1;j<=cnt1;j++)
                    {
                        if(g[g1[i]]>g[g1[j]]) swap(g1[i],g1[j]);
                    }
                }
                int del=cnt1-n/2;
                for(int i=1;i<=del;i++)
                {
                    ans-=g[g1[i]];
                }
            }
            if(cnt2>n/2)
            {
                for(int i=1;i<=cnt2;i++)
                {
                    for(int j=i+1;j<=cnt2;j++)
                    {
                        if(g[g2[i]]>g[g2[j]]) swap(g2[i],g2[j]);
                    }
                }
                int del=cnt2-n/2;
                for(int i=1;i<=del;i++)
                {
                    ans-=g[g2[i]];
                }
            }
            if(cnt3>n/2)
            {
                for(int i=1;i<=cnt3;i++)
                {
                    for(int j=i+1;j<=cnt3;j++)
                    {
                        if(g[g3[i]]>g[g3[j]]) swap(g3[i],g3[j]);
                    }
                }
                int del=cnt3-n/2;
                for(int i=1;i<=del;i++)
                {
                    ans-=g[g3[i]];
                }
            }
        }
        cout<<ans<<endl;
        /*
        if(checkA(b,c))
        {
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=a[i];
            cout<<ans<<endl;
            continue;
        }
        if(checkB(c))
        {
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++) ans+=a[i];
            cout<<ans<<endl;
            continue;
        }
        */
    }
    return 0;
}
/*
祝我3+0.5能考上！初三上期中考试顺利！初三上12月月考顺利！
语文顺利！
数学顺利！
英语顺利！
道法顺利！
物理顺利！
化学顺利！
历史顺利！
*/
