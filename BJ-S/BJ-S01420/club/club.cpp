#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,a[100001],b[100001],c[100001];
int ans=0,suma=0,sumb=0,sumc=0,maxa,maxb,maxc,maxa1,maxb1,maxc1,geshu=0;
void he(int pd)
{
    for(int i=1;i<=n;i++)
    {
        suma+=a[i];
        sumb+=b[i];
        sumc+=c[i];
        maxa=max(maxa,a[i]);
        maxb=max(maxb,b[i]);
        maxc=max(maxc,c[i]);
        maxa1=max(maxa,max(maxb,maxc));
        maxc1=min(maxa,min(maxb,maxc));
        maxb1=min(max(maxb,maxc),min(max(maxa,maxc),max(maxa,maxb)));
    }
    for(int i=1;i<=n;i++)
    {
        /*
        if(pd%3==1)
        {
            if(maxa1==a[i]||maxb1==a[i]||maxc1==a[i]){b[i]=0;a[i]=0;c[i]=0;}
        }
        if(pd%3==2)
        {
            if(maxa1==b[i]||maxb1==b[i]||maxc1==b[i]){b[i]=0;a[i]=0;c[i]=0;}
        }
        if(pd%3==0)
        {
            if(maxa1==c[i]||maxb1==c[i]||maxc1==c[i]){b[i]=0;a[i]=0;c[i]=0;}
        }*/
        //if(maxa1==a[i]||maxa1==b[i]||maxa1==c[i]){b[i]=0;a[i]=0;c[i]=0;}
        //else if(maxb1==a[i]||maxb1==b[i]||maxb1==c[i]){a[i]=0;b[i]=0;c[i]=0;}
        //else if(maxc1==a[i]||maxc1==b[i]||maxc1==c[i]){a[i]=0;b[i]=0;c[i]=0;}

        if(pd%3==1)
        {
            if(maxa1==a[i]||maxa1==b[i]||maxa1==c[i]){b[i]=0;a[i]=0;c[i]=0;return;}
        }
        else if(pd%3==2)
        {
            if(maxb1==b[i]||maxb1==a[i]||maxb1==c[i]){b[i]=0;a[i]=0;c[i]=0;return;}
        }
        else if(pd%3==0)
        {
            if(maxc1==a[i]||maxc1==b[i]||maxc1==c[i]){b[i]=0;a[i]=0;c[i]=0;return;}
        }
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        if(n==2)
        {
            int q=a[1]+b[2];
            int w=a[1]+c[2];
            int e=b[1]+a[2];
            int r=b[1]+c[2];
            int y=c[1]+a[2];
            int u=c[1]+b[2];
            cout<<max(max(max(max(max(q,w),e),r),y),u)<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            he(i);
            if(i%3==1&&geshu<n/2){he(i);ans+=maxa1;maxa1=0;}
            else if(i%3==2&&geshu<n/2){he(i);ans+=maxb1;geshu++;maxb1=0;}
            else if(i%3==0&&geshu<n/2){he(i);ans+=maxc1;geshu++;maxc1=0;}
            else if(geshu>=n/2){he(i);ans+=maxa1;maxa1=0;}
        }
        cout<<ans<<endl;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            a[i]=0;
            b[i]=0;
            c[i]=0;
        }
        suma=0;sumb=0;sumc=0;maxa=0;maxb=0;maxc=0;maxa1=0;maxb1=0;maxc1=0;geshu=0;
    }
    return 0;
}

















/*
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n;
struct node
{
    int b1,b2,b3;
}a[10001];
int quzuida()
{
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(maxn<a[i].b1);
    }
    return 0;
}
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);

    cout<<1111111;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0,sum1=0,sum2=0,sum3=0,d1,d2,d3,geshu=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].b1>>a[i].b2>>a[i].b3;
        }
        cout<<a[1].b1;

        for(int i=1;i<=n;i++)
        {
            sum1+=a[i].b1;
            sum2+=a[i].b2;
            sum3+=a[i].b3;
        }
        d1=max(sum1,max(sum2,sum3));
        d3=min(sum1,min(sum2,sum3));
        if(d1==sum1)d1=1;
        else if(d1==sum2)d1=2;
        else if(d1==sum3)d1=3;
        if(d3==sum1)d3=1;
        else if(d3==sum2)d3=2;
        else if(d3==sum3)d3=3;
        if(d1==1&&d3==2||d1==2&&d3==1)d2=3;
        else if(d1==1&&d3==3||d1==3&&d3==1)d2=2;
        else if(d1==2&&d3==3||d1==3&&d3==2)d2=1;
        //sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            if(i%3==1&&geshu<=n/2)ans+=0;//a[x].d1 zhong zui da de;=0
            if(i%3==2&&geshu<=n/2)ans+=0;//a[x].d2 zhong zui da de;=0;geshu++
            if(i%3==0&&geshu<=n/2)ans+=0;//a[x].d3 zhong zui da de;=0;geshu++
        }
    }
    //cout<<15344+19722+16441+18961+8769+13424+16178+9953+17976+10557;
    //1231231211

    return 0;
}
*/
