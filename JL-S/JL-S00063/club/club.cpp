#include <bits/stdc++.h>
using namespace std;
int a[100001][3];
int n,i,j,t,u,k;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(u=0;u<t;u++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
        for(i=0;i<n-1/2;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i][0]<a[j][0])
                    swap(a[i][0],a[j][0]);
            }
            k=k+a[i][0];
        }
        cout<<k<<endl;
    }
    return 0;
}
//Ren5Jie4Di4Ling5%
