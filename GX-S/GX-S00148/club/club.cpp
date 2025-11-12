#include<iostream>
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,maxn,maxx,x[3],num;
    for(int i=0;i<3;i++)
    {
        x[i]=0;
    }
    cin>>t>>n;
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int a1,a2,a3;
            cin>>a1>>a2>>a3;
            maxn=max(a1,a2);
            maxx=max(maxn,a3);
            if(x[0]<=n/2 && maxx==a1)
            {
                x[0]++;
                num+=a1;
            }
            else if(x[1]<=n/2 && maxx==a2)
            {
                x[1]++;
                num+=a2;
            }
            else
            {
                x[2]++;
                num+=a3;
            }
        }
        cout<<num;
    }
    return 0;
}
