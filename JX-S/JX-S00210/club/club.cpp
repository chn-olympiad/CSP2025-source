#include<bits/stdc++.h>
using namespace std;
int t,n;
struct nm//newman
{
    int a1,a2,a3;
}a[100005];
bool cmp(nm x,nm y)
{
    return x.a1>y.a1;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }

        if(a[1].a2==0&&a[1].a3==0&&a[2].a2==0&&a[2].a3==0)
        {
            long long sum=0;
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n/2;i++)
            {
                sum+=a[i].a1;
            }
            cout<<sum;
            return 0;
        }

    }
    return 0;
}
