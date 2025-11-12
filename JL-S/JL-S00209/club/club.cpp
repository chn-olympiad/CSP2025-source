#include<bits/stdc++.h>
using namespace std;
int n,m,a1[100006],a2[100006],a3[100006],a11,a22,a33;
bool pd()
{
    bool f;
    for(int i=1;i<=n;i++)
        if(a3[i]!=0)
            return false;
    return true;
}
bool p()
{
    bool f;
    for(int i=1;i<=n;i++)
        if(a2[i]!=0)
            return false;
    return true;
}
bool d()
{
    bool f;
    for(int i=1;i<=n;i++)
        if(a1[i]!=0)
            return false;
    return true;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
            cin>>a1[i]>>a2[i]>>a3[i];
        if(pd()&&p())
        {
            sort(a1+1,a1+n+1);
            for(int i=n;i>n/2;i--)
                ans+=a1[i];
        }
        else if(d()&&pd())
        {
            sort(a2+1,a2+n+1);
            for(int i=n;i>n/2;i--)
                ans+=a2[i];
        }
        else if(d()==0&&p())
        {
            sort(a3+1,a3+n+1);
            for(int i=n;i>n/2;i--)
                ans+=a3[i];
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a1[i]>=a2[i]&&a1[i]>=a3[i])
                    ans+=a1[i],a11++;
                else if(a2[i]>=a1[i]&&a2[i]>=a3[i])
                    ans+=a2[i],a22++;
                else if(a3[i]>=a2[i]&&a3[i]>=a1[i])
                    ans+=a3[i],a33++;
            }
        }
        cout<<ans;
    }
    return 0;
}
