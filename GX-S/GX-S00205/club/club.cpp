#include <bits/stdc++.h>
using namespace std;
int t,n,a[3],c,ans;
struct manyi
{
    int pai[3]={1,2,3},num[3];
}m[100005];
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    int sheng[30]={n/2,n/2,n/2};
    for(int k=1;k<=t;k++)
    {
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>m[i].num[j];
                a[j]=m[i].num[j];
            }
            for(int l=1;l<=2;l++)
            {
                if(a[1]<a[2])
                {
                    c=m[i].pai[1];
                    m[i].pai[1]=m[i].pai[2];
                    m[i].pai[2]=c;
                    c=a[1];
                    a[1]=a[2];
                    a[2]=c;
                }
                if(a[2]<a[3])
                {
                    c=m[i].pai[2];
                    m[i].pai[2]=m[i].pai[3];
                    m[i].pai[3]=c;
                    c=a[2];
                    a[2]=a[3];
                    a[3]=c;
                }
            }

        }
        for(int i=n;i>=1;i--)
        {
            if(sheng[m[n].pai[1]]>0)
            {
                sheng[m[n].pai[1]]--;
                ans+=m[n].num[m[n].pai[1]];
            }
            else if(sheng[m[n].pai[2]]>0)
            {
                sheng[m[n].pai[2]]--;
                ans+=m[n].num[m[n].pai[1]];
            }
            else
            {
                sheng[m[n].pai[3]]--;
                ans+=m[n].num[m[n].pai[3]];
            }

        }
        for(int i=1;i<=3;i++)
            cout<<sheng[m[2].pai[i]];
        cout<<ans<<endl;
    }
    return 0;
}
