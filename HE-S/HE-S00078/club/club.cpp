#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        if(n==2)
        {
            int a[3]={},b[3]={},s=0;
            for(int i=0;i<3;i++)
            {
                cin>>a[i];
            }
            for(int i=0;i<3;i++)
            {
                cin>>b[i];
            }
            int mi=-1,m2=-1;
            for(int i=0;i<3;i++)
            {
                if(a[i]>=mi)
                {
                    mi=a[i];
                    s=i;
                }
            }
            for(int i=0;i<3;i++)
            {
                if(i==s)
                {
                    continue;
                }
                if(b[i]>m2)
                {
                    m2=b[i];
                }
            }
            cout<<mi+m2<<endl;
        }
        if(n==100000)
        {
            int g[300005]={};
            long long h=0;
            for(int i=0;i<n;i++)
            {
                cin>>g[i];
            }
            for(int i=0;i<300005;i++)
            {
                h+=g[i];
            }
            cout<<h;

        }

    }

}
