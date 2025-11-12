#include <bits/stdc++.h>
using namespace std;
struct c
{
    int c1,c2,c3;
}a[100010];
bool cmp1(c x,c y)
{

    return x.c1>y.c1;
}
bool cmp2(c x,c y)
{

    return x.c2>y.c2;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int o;
    cin>>o;
    for(int k=1;k<=o;k++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
        }
        sort(a+1,a+n+1,cmp1);
        long long sum=0;
        for(int i=1;i<=n/2;i++)
        {
            sum+=a[i].c1;
            a[i].c1=0;
            a[i].c2=0;
            a[i].c3=0;
        }
        sort(a+1,a+n/2+1,cmp2);
        for(int i=1;i<=n/2;i++)
        {
            sum+=a[i].c2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
