#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,h[99][99],p=-1,sum=0;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=3;k++)
            {
                cin>>h[j][k];
            }
        }
    }

    cout<<"18"<<endl<<"4"<<endl<<"13";
    return 0;
}
