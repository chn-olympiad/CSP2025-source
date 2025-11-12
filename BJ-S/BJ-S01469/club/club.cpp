#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int low1,low2,low3;
int team1,team2,team3;
int t1=1,t2=1,t3=1;
int ans;
struct stu
{
    int f;
    int s;
    int th;
}a[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int o=t;o>=1;o--)
    {
        t1=1,t2=1,t3=1;
        ans=0;
        cin>>n;
        m = n/2;
        if(n==2)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>a[i].f>>a[i].s>>a[i].th;
            }
            ans = max(ans,a[1].f+a[2].s);
            ans = max(ans,a[1].s+a[2].f);
            ans = max(ans,a[1].f+a[2].th);
            ans = max(ans,a[1].s+a[2].th);
            ans = max(ans,a[1].th+a[2].f);
            ans = max(ans,a[1].th+a[2].s);
            cout<<ans<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cin>>a[i].f>>a[i].s>>a[i].th;
                if(a[i].f>=a[i].s&&a[i].f>=a[i].th&&team1<m)
                {
                    team1++;

                }
                else if(a[i].s>=a[i].th&&team2<m)
                {
                    team2++;
                    ans=ans+a[i].s;
                }
                else
                {
                    team3++;
                    ans=ans+a[i].th;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
