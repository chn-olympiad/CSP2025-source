#include <bits/stdc++.h>
using namespace std;
struct person
{
    int a1;
    int i1;
    int a2;
    int i2;
    int dis1;
}ct[100005];
bool rule(person c1,person c2)
{
    if(c1.dis1>c2.dis1)
        return true;
    return false;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int CE=0;CE<t;CE++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a[2]={1},b[2]={2},c[2]={3};
            cin>>a[1]>>b[1]>>c[1];
            if(b[1]>a[1])
                swap(a,b);
            if(c[1]>a[1])
                swap(a,c);
            if(c[1]>b[1])
                swap(b,c);
            ct[i].a1=a[1];
            ct[i].i1=a[0];
            ct[i].a2=b[1];
            ct[i].i2=b[0];
            ct[i].dis1=a[1]-b[1];
        }
        sort(ct+1,ct+n+1,rule);
        int sum=0,cnt[4]={0,0,0,0};
        for(int i=1;i<=n;i++)
        {
            if(cnt[ct[i].i1]<(n/2))
            {
                cnt[ct[i].i1]++;
                sum+=ct[i].a1;
            }
            else
            {
                cnt[ct[i].i2]++;
                sum+=ct[i].a2;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}