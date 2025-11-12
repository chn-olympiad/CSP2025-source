#include<bits/stdc++.h>
using namespace std;
int t,a[100010],b[100010],c[100010],ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            ans+=max(a[i],max(b[i],c[i]));
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
