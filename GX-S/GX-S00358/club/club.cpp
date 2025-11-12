#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
long long n,sum,a[MAXN][4],b[MAXN][4],num[3],cho[MAXN],sum2;
struct HH
{
    long long ver,id;
} c[MAXN],d[MAXN];
bool cmp(HH x,HH y)
{
    return x.ver>y.ver;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            sum+=a[i][0];
            b[i][1]=a[i][0]-a[i][1];
            b[i][2]=a[i][0]-a[i][2];
            c[i].ver=b[i][1]-b[i][2];
            c[i].id=i;
            sum2+=b[i][1];
        }
        long long ji=0;
        sort(c+1,c+n+1,cmp);
        /*cout<<"b:"<<endl;
        for(int i=1;i<=n;i++)
        {
            cout<<b[i][1]<<" "<<b[i][2]<<endl;
        }*/
        //cout<<"c:"<<endl;
        //for(int i=1;i<=n;i++)
        //{
        //    cout<<cho[i]<<" ";
        //}
        //cout<<endl;
        for(int i=1;i<=n/2;i++)
        {
            //cout<<c[i].ver<<" "<<c[i].id<<endl;
            cho[c[i].id]=2;
        }
        //for(int i=1;i<=n;i++)
        //{
            //cout<<cho[i]<<" ";
        //}
        //cout<<endl;
        //cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(cho[i]!=2) cho[i]=1;
            d[i].ver=b[i][cho[i]];
            d[i].id=i;
            //cout<<cho[i]<<" "<<d[i].ver<<endl;
        }
        //cout<<endl;
        sort(d+1,d+n+1,cmp);
        //for(int i=1;i<=n;i++)
        //{
            //<<d[i].ver<<" "<<d[i].id<<endl;
        //}
        //for(int i=1;i<=n;i++)
        //{
         //   cout<<cho[i]<<" ";
        //}
        //cout<<endl;
        int i=1,n2=1;
        while(i<=n/2&&d[i].ver>=0)
        {
            cho[d[i].id]=0;
            i++;
        }
        long long ans=0;
        //cout<<endl;
        for(int i=1;i<=n;i++)
        {
            //cout<<cho[i]<<" ";
            ans+=a[i][cho[i]];
        }
        //cout<<"ans:";
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
