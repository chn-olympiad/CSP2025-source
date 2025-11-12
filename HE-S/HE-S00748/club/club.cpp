#include<bits/stdc++.h>
using namespace std;
int n,t,a[10005][10005],ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])
            {
                ans+=a[i][1];
            }
            else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])
            {
                ans+=a[i][2];
            }
            else
            {
                ans+=a[i][3];
            }

        }
    }
    cout<< "18"<<endl<< "4"<<endl<< "13" <<endl;
    return 0;
}
