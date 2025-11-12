#include<bits/stdc++.h>
using namespace std;
int t,n,m[10005],a[10005][10005]={0};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int q=1;q<=t;q++)
    {
        int l=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            m[i]=max(a[i][1],max(a[i][2],a[i][3]));
        }
        for(int i=1;i<=n;i++)
        {
            l+=m[i];
        }
        cout<<l<<endl;
    }
    return 0;
}
