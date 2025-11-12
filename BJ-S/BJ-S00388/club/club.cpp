#include <bits/stdc++.h>
using namespace std;
int ta[100010];
//int b[100010];
struct l{
    int a,b,c;
    int id;
}r[100010];
bool cmpa(l a1,l b1)
{
    return a1.a>b1.a;
}
bool cmpb(l a1,l b1)
{
    return a1.b>b1.b;
}
int ans[100010];
int cnt1=0;
/*int dfs(int x)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(cnt1>n/2)
            {
                ans[x]=r[i].b;
            }
            cnt1
        }
    }
}*/
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    while(t--)
    {
        int n;
        cin >>n;
        int s1=0,s2=0,s3=0;
        for(int i=1;i<=n;i++)
        {
            cin >>r[i].a>>r[i].b>>r[i].c;
            r[i].id=i;
            s1+=r[i].a;
            s2+=r[i].b;
            s3+=r[i].c;
        }
        if(n==2)
        {
            cout <<max(r[1].a+r[2].b,max(r[1].a+r[3].b,max(r[2].a+r[1].b,max(r[2].a+r[3].b,max(r[3].a+r[1].b,r[3].a+r[2].b)))));
            continue;
        }
        /*if(n==4)
        {
            //cout <<max(r[1].a+r[2].b,max(r[1].a+r[3].b,max(r[2].a+r[1].b,max(r[2].a+r[3].b,max(r[3].a+r[1].b,r[3].a+r[2].b)))));
            //continue;
            int ansa=0;
            for(int i=1;i<=3;i++)
            {
                if(ta[i]>=n/2)
                {
                    i++;
                    ta[i]++;
                }
                ta[i]++;
                for(int i2=1;i2<=3;i2++)
                {
                    if(ta[i2]>=n/2)
                    {
                        i2++;
                        ta[i2]++;
                    }
                    ta[i2]++;
                    for(int i3=1;i3<=3;i3++)
                    {
                        if(ta[i]>=n/2)
                        {
                            i3++;
                            ta[i3]++;
                        }
                        ta[i3]++;
                        for(int i4=1;i4<=3;i4++)
                        {
                            if(ta[i4]>=n/2)
                            {
                                i4++;
                                ta[i4]++;
                            }
                            ta[i4]++;
                        }
                    }
                }
            }
        }*/
        int m1=0,m2=0,m3=0;
        if(s2==s3&&s2==0)
        {
             sort(r+1,r+n+1,cmpa);
            for(int i=1;2*i<=n;i++)
            {
                m1+=r[i].a;
            }
            cout <<m1<<endl;
            continue;
        }
        if(s1==s3&&s1==0)
        {
             sort(r+1,r+n+1,cmpb);
            for(int i=1;2*i<=n;i++)
            {
                m2+=r[i].b;
            }
            cout <<m2<<endl;
            continue;
        }

    }
    return 0;
}
