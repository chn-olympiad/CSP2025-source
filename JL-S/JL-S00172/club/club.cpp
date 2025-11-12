#include <bits/stdc++.h>
using namespace std;
struct club
{
    long long n1,n2,n3;
}x[100010];
bool cmp1(club a,club b)
{
    return min(a.n2,a.n3)<min(b.n2,b.n3);
}
bool cmp2(club a,club b)
{
    return min(a.n1,a.n3)<min(b.n1,b.n3);
}
bool cmp3(club a,club b)
{
    return min(a.n1,a.n2)<min(b.n1,b.n2);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin >> t;
    for (long long i=0;i<t;i++)
    {
        long long n,ans=0,aa1=0,aa2=0,aa3=0;
        cin >> n;
        for (long long j=0;j<n;j++)
        {
            long long a1,a2,a3;
            cin >> a1 >> a2 >> a3;
            if (a1>=a2&&a1>=a3)
            {
                x[j].n2=a1-a2;
                x[j].n3=a1-a3;
                ans+=a1;
                aa1++;
            }
            else if (a2>=a3)
            {
                x[j].n1=a2-a1;
                x[j].n3=a2-a3;
                ans+=a2;
                aa2++;
            }
            else
            {
                x[j].n1=a3-a1;
                x[j].n2=a3-a2;
                ans+=a3;
                aa3++;
            }
        }
        if (aa1>n/2)
        {
            sort(x,x+n,cmp1);
            for (long long j=0;aa1>n/2;j++)
            {
                ans-=min(x[j].n2,x[j].n3);
                aa1--;
            }
        }
        else if (aa2>n/2)
        {
            sort(x,x+n,cmp2);
            for (long long j=0;aa2>n/2;j++)
            {
                ans-=min(x[j].n1,x[j].n3);
                aa2--;
            }
        }
        else if (aa3>n/2)
        {
            sort(x,x+n,cmp3);
            for (long long j=0;aa3>n/2;j++)
            {
                ans-=min(x[j].n1,x[j].n2);
                aa3--;
            }
        }
        cout << ans << endl;
        for (long long j=0;j<n;j++)
        {
            x[j].n1=0;
            x[j].n2=0;
            x[j].n3=0;
        }
    }
    return 0;
}
