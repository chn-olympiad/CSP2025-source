#include<bits/stdc++.h>
using namespace std;
const int M=5001,K=30000000;
int a[K],b[M][M];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,t,l=1,g=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int p=a[1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[j]<a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
    int x=1,y=1;
    while(1)
    {
        b[x][y]=a[l];
        x+=g;
        l++;
        if(x>=n)
        {
            y++;
            g-=2;
        }
        if(b[x][y]==p)
        {
            break;
        }
    }
    cout<<x<<" "<<y;
    return 0;
}
