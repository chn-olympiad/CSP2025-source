#include<iostream>
#include<algorithm>
#include<cstdio>
int a[10005];
using namespace std;
int sc(int a,int b,int c)
{
    int sum=max(a,b);
    int sum1=max(b,c);
    int sum2=max(sum,sum1);
    return sum2;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t,n,cnt,cnt1=0;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            int x,y,z;
            cin>>x>>y>>z;

            cnt=sc(x,y,z);
            cnt1+=cnt;

        }

        cout<<cnt1<<endl;
        cnt1=0;
    }

    return 0;
}
