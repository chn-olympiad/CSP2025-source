#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1,n;i<=t;i++)
    {
        cin>>n;
        int a[100005]={},b[100005]={},c[100005]={},c1=0,c2=0,c3=0,maxx=(n ? n%2, n/2+1:n/2),tongji[100005][10];
        int m1=100000,m2=100000,m3=100000,mm1=0,mm2=0,mm3=0,mmm1=0,mmm2=0,mmm3=0,cnt=0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            if(a[j]>=b[j] && a[j]>=c[j])
            {
                c1++,tongji[j][1]++;
                if(m1>=a[j]&&mm1<=max(b[j],c[j]))
                {
                    m1=a[j];
                    mm1=max(b[j],c[j]);
                    mmm1=j;
                }
                cnt+=a[j];
            }
            else if(a[j]<=b[j] && b[j]>=c[j])
            {
                c2++,tongji[j][2]++;
                if(m2>=b[j]&&mm1<=max(a[j],c[j]))
                {
                    m2=b[j];
                    mm2=max(a[j],c[j]);
                    mmm2=j;
                }
                cnt+=b[j];
            }
            else
            {
                c3++,tongji[j][3]++;
                if(m3>=c[j]&&mm1<=max(b[j],a[j]))
                {
                    m3=c[j];
                    mm3=max(b[j],a[j]);
                    mmm3=j;
                }
                cnt+=c[j];
            }
        }
        if(c1>=maxx)
        {
            cnt=cnt-a[mmm1]+mm1;
        }
        if(c2>=maxx)
        {
            cnt=cnt-b[mmm2]+mm2;
        }
        if(c1>=maxx)
        {
            cnt=cnt-c[mmm3]+mm3;
        }
        cout<<cnt<<endl;
    }
}