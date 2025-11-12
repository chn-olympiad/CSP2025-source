#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
int n,t,c[4],ans,tag,d1,d2,c1,c2;
bool vis[N];
struct no{
    int a1,a2,a3;
    int maxn,maxp;
}a[N];
struct node{
    int aa,id;
};
node aa1[N],aa2[N];
bool cmp(no x,no y)
{
    return x.maxn>y.maxn;
}
bool cmpde(node x,node y)
{
    return x.aa>y.aa;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        tag=1;
        ans=0;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
            if(a[i].a2!=0) tag=2;
            if(a[i].a3!=0) tag=0;
            if(a[i].a1>=a[i].a2 && a[i].a1>=a[i].a3)
            {
                a[i].maxn=a[i].a1;
                a[i].maxp=1;
            }
            else if(a[i].a1<=a[i].a2 && a[i].a2>=a[i].a3)
            {
                a[i].maxn=a[i].a2;
                a[i].maxp=2;
            }
            else if(a[i].a3>=a[i].a2 && a[i].a1<=a[i].a3)
            {
                a[i].maxn=a[i].a3;
                a[i].maxp=3;
            }
        }
        if(tag==2)
        {
            memset(vis,0,sizeof(vis));
            d1=1,d2=1,c1=0,c2=0;
            for(int i=1;i<=n;i++)
            {
                aa1[i].id=i;
                aa2[i].id=i;
                aa1[i].aa=a[i].a1;
                aa2[i].aa=a[i].a2;
            }
            sort(aa1+1,aa1+1+n,cmpde);
            sort(aa2+1,aa2+1+n,cmpde);
            while(c1<n/2 && c2<n/2)
            {
                if(aa1[d1].aa>=aa2[d2].aa)
                {
                    if(vis[aa1[d1].id]==1)
                    {
                        for(int i=1;i<=d2;i++)
                        {
                            if(aa2[i].id==aa1[d1].id)
                            {
                                if(aa2[i].aa+aa1[d1+1].aa>=aa1[d1].aa+aa2[i+1].aa)
                                {
                                    d1++;
                                    ans+=aa1[d1].aa;
                                }
                                else{
                                    d2++;
                                    ans-=aa2[i].aa;
                                    ans+=aa1[d1].aa;
                                }
                            }
                        }
                    }
                    else
                    {
                        d1++;
                        c1++;
                        ans+=aa1[d1].aa;
                        vis[aa1[d1].id]=1;
                    }
                }
                else{
                    d2++,c2++;
                }
            }
        }
        sort(a+1,a+1+n,cmp);
        /*
        for(int i=1;i<=n;i++)
        {
            cout<<a[i].maxn<<" "<<a[i].maxp<<endl;
        }
        */
        int now=1;
        while(now<=n)
        {
            if(c[a[now].maxp]<n/2)
            {
                ans+=a[now].maxn;
                c[a[now].maxp]++;
            }
            else
            {
                //cout<<now<<endl;
                int tt=a[now].maxp;
                for(int i=now;i<=n;i++)
                {
                    if(a[i].maxp==tt)
                    {
                        if(tt==1)
                        {
                            if(a[i].a2>=a[i].a3)
                            {
                                a[i].maxn=a[i].a2;
                                a[i].maxp=2;
                            }
                            else
                            {
                                a[i].maxn=a[i].a3;
                                a[i].maxp=3;
                            }
                        }
                        else if(tt==2)
                        {
                            if(a[i].a1>=a[i].a3)
                            {
                                a[i].maxn=a[i].a1;
                                a[i].maxp=1;
                            }
                            else
                            {
                                a[i].maxn=a[i].a3;
                                a[i].maxp=3;
                            }
                        }
                        else if(tt==3)
                        {
                            if(a[i].a1>=a[i].a2)
                            {
                                a[i].maxn=a[i].a1;
                                a[i].maxp=1;
                            }
                            else
                            {
                                a[i].maxn=a[i].a2;
                                a[i].maxp=2;
                            }
                        }
                    }
                }
                sort(a+1+now,a+1+n,cmp);
                /*
                for(int i=1;i<=n;i++)
                {
                    cout<<a[i].maxn<<" "<<a[i].maxp<<endl;
                }
                */
                ans+=a[now].maxn;
                //cout<<ans<<endl;
                c[a[now].maxp]++;
            }
            now++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
