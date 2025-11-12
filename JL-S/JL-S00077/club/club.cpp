#include<bits/stdc++.h>
using namespace std;
int n,t,ans=0;
int a[3],b[3],c[3],d[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        ans=0;
        cin>>n;
        cout<<endl;
        for(int j=1; j<=n; j++)
        {
            cin>>a[i]>>b[i]>>c[i];
            cout<<endl;
            if(a[i]>b[i])
            {
                if(a[i]>c[i])
                {
                    ans+=a[i];
                    continue;
                }
                else
                {
                    ans+=c[i];
                    continue;
                }

            }
            if(b[i]>a[i])
            {
                if(b[i]>c[i])
                {
                    ans+=b[i];
                    continue;
                }
                else
                {
                    ans+=c[i];
                    continue;
                }
            }
            if(c[i]>b[i])
            {
                if(c[i]>a[i])
                {
                    ans+=c[i];
                    continue;
                }
                else
                {
                    ans+=a[i];
                    continue;
                }
            }
        }
        d[i]=ans;
    }
    for(int i=1;i<=t;i++){
        cout<<d[i]<<endl;
    }
    return 0;
}
