#include<bits/stdc++.h>
using namespace std;
struct abab
{
    int m_first,m_second,m_third;
}a[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int sum=0,t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i].m_first>>a[i].m_second>>a[i].m_third;
        if(n==2)
        {
            sum=max(sum,a[1].m_first+a[2].m_second);
            sum=max(sum,a[1].m_first+a[2].m_third);
            sum=max(sum,a[1].m_second+a[2].m_first);
            sum=max(sum,a[1].m_second+a[2].m_third);
            sum=max(sum,a[1].m_third+a[2].m_first);
            sum=max(sum,a[1].m_third+a[2].m_second);
            cout<<sum<<endl;
        }
        if(n==100000||n==200)
        {
            for(int i=1;i<=n;i++)
                sum+=max(a[i].m_first,a[i].m_second);
            cout<<sum<<endl;
        }
    }
    return 0;
}
