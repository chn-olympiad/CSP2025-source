#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n,i,j,k,t,a[1000][1000];
    cin>>t;
    for(k=0;k<t;k++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                cin>>a[i][j];
            }
        }
    }
    int c=0,cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(a[i][j]>c)
                c=a[i][j];
        }
        cnt+=c;
    }
    cout<<cnt;
    return 0;
}
