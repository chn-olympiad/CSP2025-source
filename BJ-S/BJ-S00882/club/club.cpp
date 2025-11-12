#include <bits/stdc++.h>
using namespace std;
long long t,n,cnt1,cnt2,cnt3,sum,m1,k1;
struct child
{
    long long a,b,c,ma,mi,jian1;
    bool select;
};
bool cmp1(child x,child y)
{
    if(x.jian1<y.jian1)
    {
        return true;
    }
    return false;
}
child s[100006];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        cnt1=0;
        cnt2=0;
        cnt3=0;
        sum=0;
        m1=0;
        for(int j=1;j<=n;j++)
        {
            s[j].select=false;
            cin>>s[j].a>>s[j].b>>s[j].c;
            if(max(s[j].a,max(s[j].b,s[j].c))==s[j].a)
            {
                cnt1++;
                s[j].ma=s[j].a;
            }
            else if(max(s[j].a,max(s[j].b,s[j].c))==s[j].b)
            {
                cnt2++;
                s[j].ma=s[j].b;
            }
            else
            {
                cnt3++;
                s[j].ma=s[j].c;
            }
            if(min(s[j].a,min(s[j].b,s[j].c))==s[j].a)
            {
                s[j].mi=s[j].a;
            }
            else if(min(s[j].a,min(s[j].b,s[j].c))==s[j].b)
            {
                s[j].mi=s[j].b;
            }
            else
            {
                s[j].mi=s[j].c;
            }
            s[j].jian1=s[j].ma-(s[j].a+s[j].b+s[j].c-s[j].ma-s[j].mi);
        }
            if(max(cnt1,max(cnt2,cnt3))==cnt1)
            {
                m1=cnt1;
                k1=1;
            }
            else if(max(cnt1,max(cnt2,cnt3))==cnt2)
            {
                m1=cnt2;
                k1=2;
            }
            else
            {
                m1=cnt3;
                k1=3;
            }
            if(m1<=n/2)
            {
                for(int j=1;j<=n;j++)
                {
                    sum+=s[j].ma;
                }
                cout<<sum<<endl;
            }
            else
            {
                sort(s+1,s+n+1,cmp1);
                long long p=1;
                while(m1>n/2)
                {
                    if((s[p].ma==s[p].a&&k1==1)||(s[p].ma==s[p].b&&k1==2)||(s[p].ma==s[p].c&&k1==3))
                    {
                        sum+=s[p].a+s[p].b+s[p].c-s[p].ma-s[p].mi;
                        s[p].select=true;
                        m1--;
                        p++;
                    }

                }
                for(int j=1;j<=n;j++)
                {
                    if(!s[j].select)
                    {
                        sum+=s[j].ma;
                    }
                }
                cout<<sum<<endl;
            }
    }
    return 0;
}
