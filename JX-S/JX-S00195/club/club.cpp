#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],ans,an[100005];
bool cmp(int l,int r)
{
    return l>r;
}
int main()
{
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
            an[i]=a[i][0];
        }
        sort(an,an+n,cmp);
        for(int i=0;i<n/2;i++)
        {
            ans+=an[i];
        }
    }
    cout<<ans;
    return 0;
}
