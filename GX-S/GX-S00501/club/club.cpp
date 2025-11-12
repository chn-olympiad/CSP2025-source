#include<bits/stdc++.h>
using namespace std;
struct node
{
    int bm1,bm2,bm3;
    bool us1,us2,us3;
};
bool cmp1(node a,node b)
{
     return a.bm1>b.bm1;
}
bool cmp2(node a,node b)
{
     return a.bm2>b.bm2;
}
bool cmp3(node a,node b)
{
     return a.bm3>b.bm3;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        node a[n+10];
        for(int i=0;i<n;i++)a[i].us1=a[i].us2=a[i].us3=false;
        for(int i=0;i<n;i++)cin>>a[i].bm1>>a[i].bm2>>a[i].bm3;
        int m1=0,m2=0,m3=0;
        int ans=0;
        sort(a,a+n,cmp1);
        int edge=0;
        while(m1<n/2&&edge<n)
        {
            if(a[edge].bm1>a[edge].bm2&&a[edge].bm1>a[edge].bm3)
            {
                a[edge].us1=true;
                ans+=a[edge].bm1;
                m1+=1;
            }
            edge++;
        }
        sort(a,a+n,cmp2);
        edge=0;
        while(m2<n/2&&edge<n)
        {
            if(a[edge].bm2>a[edge].bm3&&a[edge].us1==false)
            {
                a[edge].us2=true;
                ans+=a[edge].bm2;
                m2+=1;
            }
            edge++;
        }
        sort(a,a+n,cmp3);
        edge=0;
        while(m3<n/2&&edge<n)
        {
            if(a[edge].us2==false&&a[edge].us1==false)
            {
                a[edge].us3=true;
                ans+=a[edge].bm3;
                m3+=1;
            }
            edge++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
