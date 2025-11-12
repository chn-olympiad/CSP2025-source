#include<bits/stdc++.h>
using namespace std;
int r[110];
int s[110];
bool sdf=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int xm;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int t;
            cin>>t;
            if(sdf==0)
            {
                xm=t;
                sdf=1;
            }
            r[t]++;
        }
    }

    int x=0,t=0;
    for(int i=100;i>=0;i--)
    {
        if(r[i]!=0)
        {
            x++;

        }
        if(i==xm)
        {
            t=x;

        }
    }

    int lie,hang;

    for(int j=1;j<=m;j++)
    {
        if(j%2==1&&(t>=(j-1)*n+1)&&(t<=j*n))
        {
            lie=j;
            hang=t-((j-1)*n+1)+1;
        }
        if(j%2==0&&(t<=j*n)&&(t>=(j-1)*n+1))
        {
            lie=j;
            hang=j*n-t+1;
        }
    }
    cout<<lie<<" "<<hang;
    return 0;
}
