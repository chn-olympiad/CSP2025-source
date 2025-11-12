#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int x=0,y=0,z=0;
        for (int i=0; i<n; i++)
        {
           cin>>a[i];
           cin>>b[i]>>c[i];
        }
        int ret=0;
        for (int i=0; i<n; i++)
        {
            int mx=max(a[i],max(b[i],c[i]));
            if (mx==a[i])
            {
                ret+=a[i];
            }
            else if(mx==b[i])
            {

                ret+=b[i];
            }
            else
            {
                ret+=c[i];
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
