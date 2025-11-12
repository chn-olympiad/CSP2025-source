#include<bits/stdc++.h>
using namespace std;
int n,d[4][50005],l;
struct student
{
    int a[4];
    int mase=-1;
    int r=1;
}a[100005];
int mass(int a,int b,int c,int x)
{
    int mi=a,ma=a,mii=1,maa=1;
    if(b<mi)mi=b,mii=2;
    if(b>ma)ma=b,maa=2;
    if(c<mi)mi=c,mii=3;
    if(c>ma)ma=c,maa=3;
    if(mii==maa)maa=2;
    if(x==1)return maa;
    if(x==2)return 6-maa-mii;
    return mii;
}
int mase(int i)
{
    if(a[i].mase!=-1)return a[i].mase;
    a[i].mase=a[i].a[mass(a[i].a[1],a[i].a[2],a[i].a[3],1)]-a[i].a[mass(a[i].a[1],a[i].a[2],a[i].a[3],2)];
    return a[i].mase;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,mas;
    cin>>t;
    while(t--)
    {
        memset(d,-1,sizeof(d));
        d[1][0]=d[2][0]=d[3][0]=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3];
        for(int i=1;i<=n;i++)
        {
            mas=mass(a[i].a[1],a[i].a[2],a[i].a[3],1);
            if(mas!=l)
            {
                d[mas][++d[mas][0]]=i;
                if(d[mas][0]==n/2)l=mas;
                a[i].r=mas;
            }
            else
            {
                int mi=0x3f3f3f,mii=1;
                for(int j=1;j<=n/2;j++)
                {
                    if(mase(d[mas][j])<mi)
                    {
                        mii=j;
                        mi=mase(d[mas][j]);
                    }
                }
                if(mase(i)<=mi)
                {
                    mas=mass(a[i].a[1],a[i].a[2],a[i].a[3],2);
                    d[mas][++d[mas][0]]=i;
                    a[i].r=mas;
                }
                else
                {
                    d[mas][mii]=i;
                    a[i].r=mas;
                    mas=mass(a[mii].a[1],a[mii].a[2],a[mii].a[3],2);
//                    cout<<a[mii].a[1]<<' '<<a[mii].a[2]<<' '<<a[mii].a[3]<<endl;
                    d[mas][++d[mas][0]]=mii;
                    a[mii].r=mas;
                }
//                cout<<a[1].r<<endl;
            }
        }
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
//            cout<<i<<' '<<a[i].r<<' '<<a[i].a[a[i].r]<<' '<<sum<<endl;
            sum+=a[i].a[a[i].r];
        }
        cout<<sum<<endl;
    }
    return 0;
}
