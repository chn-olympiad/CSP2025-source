#include <bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int a[100010][4];
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]) a[i][0]=1;
            else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]) a[i][0]=2;
            else a[i][0]=3;
        }
        int t[4]={0,0,0,0};
        for(int i=1;i<=n;i++)
            t[a[i][0]]++;
        for(int i=1;i<=3;i++)
        {
            if(t[i]<=n/2) continue;
            int x=t[i]-n/2;
            while(x--)
            {
                int v=1000000,l;
                for(int j=1;j<=n;j++)
                {
                    if(a[j][0]!=i) continue;
                    if(a[j][i]<v)
                    {
                        v=a[j][i];
                        l=j;
                    }
                }
                a[l][i]=-1;
                for(int j=1;j<=3;j++)
                    if(a[l][0]!=j&&a[l][a[l][0]]<a[l][j])
                        a[l][0]=j;

            }
        }

        int num=0;
        for(int i=1;i<=n;i++)
            num+=a[i][a[i][0]];
        //for(int i=1;i<=n;i++)
            //cout<<a[i][0]<<" ";
        //cout<<endl;
        cout<<num<<endl;
    }
    return 0;
}
