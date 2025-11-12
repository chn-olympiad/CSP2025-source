#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;
    int f,s,t;
};
bool cmp(node x,node y)
{
    if(x.a!=y.a) return x.a>y.a;
    else if(x.b!=y.b) return x.b>y.b;
    else return x.c>y.c;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        node a[n+1]={};
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].a>a[i].b)//a>b
            {
                if(a[i].c>a[i].a) //c>a>b
                {
                    a[i].f=3;
                    a[i].s=1;
                    a[i].t=2;
                }
                else //a>all
                {
                    if(a[i].b>a[i].c)//a>b>c
                    {
                        a[i].f=1;
                        a[i].t=3;
                        a[i].s=2;
                    }
                    else//a>c>b
                    {
                        a[i].f=1;
                        a[i].s=3;
                        a[i].t=2;
                    }
                }
            }
            else//a<=b
            {
                if(a[i].c>a[i].b) //c>b>a
                {
                    a[i].f=3;
                    a[i].s=2;
                    a[i].t=1;
                }
                else //b>all
                {
                    if(a[i].a>a[i].c)//b>a>c
                    {
                        a[i].f=2;
                        a[i].s=1;
                        a[i].t=3;
                    }
                    else//b>c>a
                    {
                        a[i].f=2;
                        a[i].s=3;
                        a[i].t=1;
                    }
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        int aa=0,ba=0,ca=0;
        int ac=0,bc=0,cc=0;
        bool af=false,bf=false,cf=false;
        for(int i=1;i<=n;i++)
        {
            if(a[i].f==1)
            {
                if(!af)
                {
                    ac++;
                    aa+=a[i].a;
                    if(ac>=(n/2))
                    {
                        af=true;
                    }
                }
                else
                {
                    if(a[i].s==2 && !bf)
                    {
                        bc++;
                        ba+=a[i].b;
                        if(bc>=(n/2))
                        {
                            bf=true;
                        }
                    }
                    else if(a[i].s==3 && !cf)
                    {
                        cc++;
                        ca+=a[i].c;
                        if(cc>=(n/2))
                        {
                            cf=true;
                        }
                    }
                    else
                    {
                        if(a[i].t==2)
                        {
                            bc++;
                            ba+=a[i].b;
                            if(bc>=(n/2))
                            {
                                bf=true;
                            }

                        }
                        if(a[i].t==3)
                        {
                            cc++;
                            ca+=a[i].c;
                            if(cc>=(n/2))
                            {
                                cf=true;
                            }
                        }
                    }
                }
            }
            if(a[i].f==2)
            {
                if(!bf)
                {
                    bc++;
                    ba+=a[i].b;
                    if(bc>=(n/2))
                    {
                        bf=true;
                    }
                }
                else
                {
                    if(a[i].s==1 && !af)
                    {
                        ac++;
                        aa+=a[i].a;
                        if(ac>=(n/2))
                        {
                            af=true;
                        }
                    }
                    else if(a[i].s==3 && !cf)
                    {
                        cc++;
                        ca+=a[i].c;
                        if(cc>=(n/2))
                        {
                            cf=true;
                        }
                    }
                    else
                    {
                        if(a[i].t==1)
                        {
                            ac++;
                            aa+=a[i].a;
                            if(ac>=(n/2))
                            {
                                af=true;
                            }

                        }
                        if(a[i].t==3)
                        {
                            cc++;
                            ca+=a[i].c;
                            if(cc>=(n/2))
                            {
                                cf=true;
                            }
                        }
                    }
                }
            }
            if(a[i].f==3)
            {
                if(!cf)
                {
                    cc++;
                    ca+=a[i].c;
                    if(cc>=(n/2))
                    {
                        cf=true;
                    }
                }
                else
                {
                    if(a[i].s==2 && !bf)
                    {
                        bc++;
                        ba+=a[i].b;
                        if(bc>=(n/2))
                        {
                            bf=true;
                        }
                    }
                    else if(a[i].s==1 && !af)
                    {
                        ac++;
                        aa+=a[i].a;
                        if(ac>=(n/2))
                        {
                            af=true;
                        }
                    }
                    else
                    {
                        if(a[i].t==2)
                        {
                            bc++;
                            ba+=a[i].b;
                            if(bc>=(n/2))
                            {
                                bf=true;
                            }

                        }
                        if(a[i].t==1)
                        {
                            ac++;
                            aa+=a[i].a;
                            if(ac>=(n/2))
                            {
                                af=true;
                            }
                        }
                    }
                }
            }
        }
        cout<<ca+aa+ba<<endl;
    }
    return 0;
}
