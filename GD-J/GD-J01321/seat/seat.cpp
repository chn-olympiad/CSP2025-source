#include<bits/stdc++.h>
using namespace std;
int x,y,a1,a[10][10],c[100],n;
bool p(int w,int e)
{
    return w>e;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>x>>y>>a1;
    c[0]=a1;
    for(int i=1;i<x*y;i++)
        cin>>c[i];
    sort(c,c+x*y,p);
    if(x*y%2==0)
    {
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
                a[j][i]=c[n++];
            i++;
            for(int j=y-1;j>=0;j--)
                a[j][i]=c[n++];
        }
    }
    else
    {
        for(int i=0;i<x-1;i++)
        {
            for(int j=0;j<y;j++)

                a[j][i]=c[n++];
            i++;
            for(int j=y-1;j>=0;j--)
                a[j][i]=c[n++];

        }
        for(int j=0;j<y;j++)
             a[j][x-1]=c[n++];
    }
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            if(a[i][j]==a1)
            {
                cout<<j+1<<" "<<i+1;
                break;
            }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
