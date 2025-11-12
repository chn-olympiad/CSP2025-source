#include <bits/stdc++.h>
using namespace std;
struct student
{
    int d[5]={0};
}a[100002];
bool cmp(student a,student b)
{
    return a.d[1]>b.d[1];
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
        bool isa=true;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].d[1]>>a[i].d[2]>>a[i].d[3];
            if(a[i].d[2]!=0||a[i].d[3]!=0)
                isa=false;
        }
        if(isa)
        {
            sort(a+1,a+n+1,cmp);
            int sum=0;
            for(int i=1;i<=n/2;i++)
            {
                sum+=a[i].d[1];
            }
            cout<<sum<<endl;
            continue;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=max(a[i].d[1],max(a[i].d[2],a[i].d[3]));
        }
        cout<<sum<<endl;
    }
    return 0;
}

