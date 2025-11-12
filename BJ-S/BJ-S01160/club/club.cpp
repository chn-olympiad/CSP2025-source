#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct A
{
    long long a1,a2,a3;
    long long k,t,c;
};
bool cmp(A x,A y)
{
    return x.t>y.t;
}
A a[100010];
int b[10];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(b,0,sizeof(b));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
            a[i].k=max(a[i].a1,max(a[i].a2,a[i].a3));
            if(a[i].k==a[i].a1)
            {
                a[i].t=min(a[i].k-a[i].a2,a[i].k-a[i].a3);
                a[i].c=1;
            }
            if(a[i].k==a[i].a2)
            {
                a[i].t=min(a[i].k-a[i].a1,a[i].k-a[i].a3);
                a[i].c=2;
            }
            if(a[i].k==a[i].a3)
            {
                a[i].t=min(a[i].k-a[i].a1,a[i].k-a[i].a2);
                a[i].c=3;
            }
        }
        sort(a+1,a+n+1,cmp);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            if(b[a[i].c]==n/2)
            {
                sum+=a[i].k-a[i].t;
            }
            else
            {
                sum+=a[i].k;
                b[a[i].c]++;
            }

        }
        cout<<sum<<endl;
    }

}