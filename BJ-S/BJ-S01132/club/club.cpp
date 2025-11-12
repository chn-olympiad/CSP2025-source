#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n+1][4]={};
        int m[4]={};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i][j];
            }

        }
        for(int j=1;j<=3;j++)
        {
            int s[n+1]={},s1[n/2+1]={};
            for(int i=1;i<=n;i++)
            {
                s[i]=a[i][j];
                //cout<<s[i]<<" ";
            }
            sort(s+1,s+n+1);
            int tt=1;
            for(int i=1;i<=n;i++)
            {
                for(int k=1;k<=n;k++)
                {
                    if(a[i][j]==s[k]&&k<n/2)
                    {
                        s1[tt]=a[i][j];
                    }
                }

            }
            
            for(int i=n;i>n/2;i--)
            {
                m[j]+=s[i];
            }

        }

    }
    return 0;
}
