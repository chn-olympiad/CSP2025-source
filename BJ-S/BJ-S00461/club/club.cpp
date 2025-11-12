#include<bits/stdc++.h>
using namespace std;
int t,n,in[3][100005],in1[100005],z;
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
            for(int k=1;k<=3;k++)
            {
                cin>>in[k][j];
            }
            in1[j]=in[1][j];
        }
        sort(in1+1,in1+n+1);
        for(int j=n;j>n/2;j--)
        {
            z+=in1[j];
        }
        cout<<z;
    }
    return 0;
}
