#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n,s,a,b,c,ma;
int llss[5];
struct zjh{
    int a1,a2,a3;
};
zjh ls[222222];

bool cmp(zjh x,zjh y)
{
    int x1,x2,x3,y1,y2,y3;
    if(x.a1>=x.a2&&x.a2>=x.a3)
    {
        x1=x.a1;
        x2=x.a2;
        x3=x.a3;
    }
    if(x.a1>=x.a3&&x.a3>=x.a2)
    {
        x1=x.a1;
        x2=x.a3;
        x3=x.a2;
    }
    if(x.a2>=x.a1&&x.a1>=x.a3)
    {
        x1=x.a2;
        x2=x.a1;
        x3=x.a3;
    }
    if(x.a2>=x.a3&&x.a3>=x.a1)
    {
        x1=x.a2;
        x2=x.a3;
        x3=x.a1;
    }
    if(x.a3>=x.a1&&x.a1>=x.a2)
    {
        x1=x.a3;
        x2=x.a1;
        x3=x.a2;
    }
    if(x.a3>=x.a2&&x.a2>=x.a1)
    {
        x1=x.a3;
        x2=x.a2;
        x3=x.a1;
    }
    if(y.a1>=y.a2&&y.a2>=y.a3)
    {
        y1=y.a1;
        y2=y.a2;
        y3=y.a3;
    }
    if(y.a1>=y.a3&&y.a3>=y.a2)
    {
        y1=y.a1;
        y2=y.a3;
        y3=y.a2;
    }
    if(y.a2>=y.a1&&y.a1>=y.a3)
    {
        y1=y.a2;
        y2=y.a1;
        y3=y.a3;
    }
    if(y.a2>=y.a3&&y.a3>=y.a1)
    {
        y1=y.a2;
        y2=y.a3;
        y3=y.a1;
    }
    if(y.a3>=y.a1&&y.a1>=y.a2)
    {
        y1=y.a3;
        y2=y.a1;
        y3=y.a2;
    }
    if(y.a3>=y.a2&&y.a2>=y.a1)
    {
        y1=y.a3;
        y2=y.a2;
        y3=y.a1;
    }
    if(x1==y1)
    {
        if(x2==y2)
        {
            return x3>=y3;
        }
        else return x2>y2;
    }
    else return x1>y1;
}

void dfs(int x,int s,int aa,int bb,int cc)
{
    if(x==n+1)
    {
        ma=max(ma,s);
        return;
    }
    if(aa<n/2)
    {
        dfs(x+1,s+ls[x].a1,aa+1,bb,cc);
    }
    if(bb<n/2)
    {
        dfs(x+1,s+ls[x].a2,aa,bb+1,cc);
    }
    if(cc<n/2)
    {
        dfs(x+1,s+ls[x].a3,aa,bb,cc+1);
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        ma=0;
        s=0;
        llss[1]=0;
        llss[2]=0;
        llss[3]=3;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>ls[i].a1>>ls[i].a2>>ls[i].a3;
        }
        if(n>100)
        {
            sort(ls+1,ls+1+n,cmp);
            for(int i=1;i<=n;i++)
            {
                int mi;
                int mx=max(ls[i].a1,max(ls[i].a2,ls[i].a3));
                if(ls[i].a1==mx) mi=1;
                if(ls[i].a2==mx) mi=2;
                if(ls[i].a3==mx) mi=3;
                if(llss[mi]<n/2)
                {
                    s+=mx;
                    llss[mi]++;
                    continue;
                }
                int mj,my,mk,mz;
                if(mi==1)
                {
                    if(ls[i].a2>=ls[i].a3)
                    {
                        mj=2;
                        my=ls[i].a2;
                    }
                    else
                    {
                        mj=3;
                        my=ls[i].a3;
                    }
                    if(llss[mj]<=n/2)
                    {
                        s+=my;
                        llss[mj]++;
                    }
                    else
                    {
                        s+=mz;
                        llss[mz]++;
                    }
                    continue;
                }

                if(mi==2)
                {
                    if(ls[i].a1>=ls[i].a3)
                    {
                        mj=1;
                        my=ls[i].a1;
                    }
                    else
                    {
                        mj=3;
                        my=ls[i].a3;
                    }
                    if(llss[mj]<=n/2)
                    {
                        s+=my;
                        llss[mj]++;
                    }
                    else
                    {
                        s+=mz;
                        llss[mz]++;
                    }
                    continue;
                }

                if(mi==3)
                {
                    if(ls[i].a2>=ls[i].a1)
                    {
                        mj=2;
                        my=ls[i].a2;
                    }
                    else
                    {
                        mj=1;
                        my=ls[i].a1;
                    }
                    if(llss[mj]<=n/2)
                    {
                        s+=my;
                        llss[mj]++;
                    }
                    else
                    {
                        s+=mz;
                        llss[mz]++;
                    }
                    continue;
                }
            }
            cout<<s;
        }
        else
        {
            dfs(0,0,0,0,0);
            cout<<ma;
        }
        cout<<endl;
    }
    return 0;
}
