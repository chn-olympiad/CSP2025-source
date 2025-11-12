#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100000+5],b[100000+5],c[100000+5],max_v;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j]>>b[j]>>c[j];
            max_v+=max(a[j],max(b[j],c[j]));
        }
        cout<<max_v<<endl;
        max_v=0;
    }
    return 0;
}
