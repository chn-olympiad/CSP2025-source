#include<bits/stdc++.h>
using namespace std;
struct node
{
    long long aa,bb,cc;
    double a1,a2,a3;
};
node a[100005],b[100005],c[100005],d[100005];
bool funa(node a1,node a2)
{
    if(a1.a1!=a2.a1)
        return a1.a1>a2.a1;
    else if(a1.aa!=a2.aa)
        return a1.aa>a2.aa;
    else if(a1.bb!=a2.bb)
        return a1.bb>a2.bb;
    else
        return a1.cc>a2.cc;
}
bool func(node aa1,node aa2)
{
    if(aa1.a3!=aa2.a3)
        return aa1.a3>aa2.a3;
    else if(aa1.cc!=aa2.cc)
        return aa1.cc>aa2.cc;
    else if(aa1.aa!=aa2.aa)
        return aa1.aa>aa2.aa;
    else
        return aa1.bb>aa2.bb;
}
bool funb(node aa1,node aa2)
{
    if(aa1.a2!=aa2.a2)
        return aa1.a2>aa2.a2;
    else if(aa1.bb!=aa2.bb)
        return aa1.bb>aa2.bb;
    else if(aa1.aa!=aa2.aa)
        return aa1.aa>aa2.aa;
    else
        return aa1.cc>aa2.cc;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    scanf("%lld",&t);
    for(int i=1;i<=t;i++)
    {
        long long n;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&d[i].aa,&d[i].bb,&d[i].cc);
            a[i].aa=b[i].aa=c[i].aa=d[i].aa;
            a[i].bb=b[i].bb=c[i].bb=d[i].bb;
            a[i].cc=b[i].cc=c[i].cc=d[i].cc;
            double ssum=d[i].aa+d[i].bb+d[i].cc;
            a[i].a1=b[i].a1=c[i].a1=ssum*0.1/d[i].aa*0.1;
            a[i].a2=b[i].a2=c[i].a2=ssum*0.1/d[i].bb*0.1;
            a[i].a3=b[i].a3=c[i].a3=ssum*0.1/d[i].cc*0.1;
        }
        sort(a+1,a+n+1,funa);
        sort(b+1,b+n+1,funb);
        sort(c+1,c+n+1,func);
        long long sum1=0,sum2=0,sum3=0,suma=0,sumb=0,sumc=0;
        for(int i=1;i<=n;i++)
        {
            if(suma<n/2)
            {
                sum1+=a[i].aa;
                suma++;
            }
            else if(a[i].bb<a[i].cc&&sumc<n/2)
            {
                sumc++;
                sum1+=a[i].cc;
            }
            else if(a[i].bb>a[i].cc&&sumb<n/2)
            {
                sumb++;
                sum1+=a[i].bb;
            }
        }
        suma=0,sumb=0,sumc=0;
        for(int i=1;i<=n;i++)
        {
            if(sumb<n/2)
            {
                sum2+=b[i].bb;
                sumb++;
            }
            else if(b[i].aa<b[i].cc&&sumc<n/2)
            {
                sumc++;
                sum2+=b[i].cc;
            }
            else if(b[i].aa>b[i].cc&&suma<n/2)
            {
                suma++;
                sum2+=b[i].aa;
            }
        }
        suma=0,sumb=0,sumc=0;
        for(int i=1;i<=n;i++)
        {
            if(sumc<n/2)
            {
                sumc++;
                sum3+=c[i].cc;
            }
            else if(c[i].aa<c[i].bb&&sumb<n/2)
            {
                sumb++;
                sum3+=c[i].bb;
            }
            else if(c[i].aa>c[i].bb&&suma<n/2)
            {
                suma++;
                sum3+=c[i].aa;
            }
        }
        cout<<max(sum1,max(sum2,sum3))<<endl;
    }
    return 0;
}//Ren5Jie4Di4Ling5
