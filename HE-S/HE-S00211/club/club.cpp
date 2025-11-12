#include<bits/stdc++.h>
using namespace std;
int t=0,n=0;
int a1=0,a2=0,a3=0;
int sum=0;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int x=0;x<t;x++)
    {
        for(int y=0;y<t;y++)
        {
            cin>>n;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<3;j++)
                {
                    cin>>a1>>a2>>a3;
                    if(a1>a2&&a1>a3)
                    {
                        sum=sum+a1;
                    }
                    if(a2>a1&&a2>a3)
                    {
                        sum=sum+a2;
                    }
                    if(a3>a1&&a3>a2)
                    {
                        sum=sum+a3;
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
