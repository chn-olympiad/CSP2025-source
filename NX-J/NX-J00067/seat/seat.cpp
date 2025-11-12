#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    bool f=1;
    int m,n,a=0,o;
    cin>>m>>n;
    int t[m*n];
    for(int i=1;i<=n*m;i++)
    {
        cin>>t[i];
    }
    int r=t[2];
    for(int i=0;i<=m*n;i++)
    {
        for(int j=0;j<=m*n;j++)
        {
            if(t[j]<t[j+1])
            {
                o=t[j+1];
                t[j+1]=t[j];
                t[j]=o;
            }
        }
    }
    int x=0,y=0;
    for(int i=1;i<n*m;i++)
    {
        if(i%n==1)
        {
            f=1;
        }
        else
        {
            f=0;
        }
        if(f==1)
        {
            x++;
        }
        else
        {
            x--;
        }
        y=i/n;
        if(t[i]==r)
        {
            cout<<x+1<<" "<<y+1;
        }
    }
    return 0;
}
