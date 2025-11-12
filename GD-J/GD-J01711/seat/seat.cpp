#include<bits/stdc++.h>
using namespace std;
int a[20][20],b[420];
bool flag,ji,ou;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,temp=0;
    cin>>n>>m;
    if(m%2==0)
    {
        ou = 1;
    }
    if(m%2==1)
    {
        ji = 1;
    }
    for(int i=1;i<=n*m;i++)
    {

            cin>>b[i];
            temp = b[1];

            if(b[i]==i)
            {
                if(m%2==0)
                {
                    ou = 1;
                }
                if(m%2==1)
                {
                    ji = 1;
                }
            }
            else if(b[i]==n*m-i+1)
            {
                flag = 1;
            }
    }
    sort(b+1,b+n*m+1);
    if(m==1 && n==1 || flag == 1 || temp==b[n*m])
    {
        cout<<1<<" "<<1;
    }
    else if(temp==b[1])
    {

        if(ou == 1)
        {
         cout<<m<<" "<<1;
        }
        if(ji==1)
        {
         cout<<m<<" "<<n;
        }
    }

    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
        }

    }*/

    return 0;
}

