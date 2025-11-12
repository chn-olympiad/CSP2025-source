#include<bits/stdc++.h>
using namespace std;
struct st
{
    int h;
    int bm1;
    int bm2;
    int bm3;
    int pm1;
    int pm2;
    int pm3;
    bool xuan;
};
st a[100086];
bool cmp1(st x,st y)
{
    return x.bm1>y.bm1;
}
bool cmp2(st x,st y)
{
    return x.bm2>y.bm2;
}
bool cmp3(st x,st y)
{
    return x.bm3>y.bm3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int l;
    cin>>l;
    for(int o=1;o<=l;o++)
    {
        for(int i=1;i<=10086;i++)
        {
            a[i].xuan=false;
        }
        int sum=0;
        int n;
        cin>>n;
        int n2=n/2;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].bm1>>a[i].bm2>>a[i].bm3;
        }
        int b1=0,b2=0,b3=0;
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++)
        {
            a[i].pm1=i;
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++)
        {
            a[i].pm2=i;
        }
        sort(a+1,a+n+1,cmp3);
        for(int i=1;i<=n;i++)
        {
            a[i].pm3=i;
        }
        for(int i=1;i<=n;i++)
        {
            if(b3>=n2)
            {
                break;
            }
//            if(a[i].bm1>a[i].bm2&&a[i].bm1>a[i].bm3&&a[i].xuan==false)
//            {
//                a[i].xuan=true;
//                b1++;
//                sum+=a[i].bm1;
//            }
            if(a[i].pm1>n2&&a[i].pm2>n2&&a[i].xuan==false)
            {
                a[i].xuan=true;
                b3++;
                sum+=a[i].bm3;
            }
        }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++)
        {
            if(b2>=n2)
            {
                break;
            }
            if(a[i].pm1>n2&&a[i].xuan==false)
            {
                a[i].xuan=true;
                b2++;
                sum+=a[i].bm2;
            }
        }
        sort(a+1,a+n+1,cmp1);
        for(int i=1;i<=n;i++)
        {
            if(b1>=n2)
            {
                break;
            }
            if(a[i].xuan==false)
            {
                a[i].xuan=true;
                b1++;
                sum+=a[i].bm1;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}//什么鬼
