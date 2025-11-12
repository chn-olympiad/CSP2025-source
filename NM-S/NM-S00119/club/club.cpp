#include <bits/stdc++.h>
using namespace std;
int t,n,a[10005][4],b=0,c=0,d=0,ans=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int m=1;m<=t;m++)
    {
        int max;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
                if(a[i][2]<a[i][1]&&a[i][3]<a[i][1])
                    max=a[i][1];
                    b=max++;
                if(a[i][1]<a[i][2]&&a[i][3]<a[i][2])
                    max=a[i][2];
                    c=max++;
                if(a[i][1]<a[i][3]&&a[i][2]<a[i][3])
                    max=a[i][3];
                    d=max++;
                    ans=b+c+d;
            }
        cout<<ans<<endl;
    }
    return 0;
}
