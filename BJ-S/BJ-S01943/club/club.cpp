#include<bits/stdc++.h>
using namespace std;
struct stu
{
    int a[4];
    int p;
};
bool cmd(stu c,stu b)
{
    if(c.a[1]>b.a[1]) return true;
    return false;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum=0;
        cin>>n;
        stu k[1e5+5];
        for(int i=1;i<=n;i++)
        {
            cin>>k[i].a[1]>>k[i].a[2]>>k[i].a[3]>>endl;
            k[i].p=0;
        }
        int numx=1;
        for(int i=1;i<=n;i++)
        {
            int m=max(k[i].a[1],max(k[i].a[2],k[i].a[3]));
            if(m==k[i].a[1]) p=1;
            if(m==k[i].a[2]) p=2;
            if(m==k[i].a[3]) p=3;
            sort(k[i].a,k[i].a+3);
        }
        sort(k,k+n,cmd);
        int q[4];
        for(int i=1;i<=n;i++)
        {
            q[k[i].p]++;
            int e[2];
            for(int i=0;i<=1;i++)
            {
                if(i==p-1) continue;
                else e[i]=i+1;
            }
            if(q[k[i].p]>n/2)
            {
                q[k[i].p]--;
                if(k[i].a[2]>=k[i].a[3]) p=e[0];
                if(k[i].a[2]<k[i].a[3]) p=e[1];
                q[k[i].p]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            sum+=k[i].a[k[i].p];
        }
        cout<<sum<<endl;
    }
    return 0;
}