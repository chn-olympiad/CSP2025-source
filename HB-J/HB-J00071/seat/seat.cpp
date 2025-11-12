#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int q[11][11];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int l=n*m;
    for (int i=1;i<=l;i++)
    {
        cin>>a[i];
    }
    int r=a[1];
    sort(a,a+l+1);
    int d=0,index=l-1;
    int x=1,y=1;
    int flag=1;
    q[1][1]=a[l];
    //for (int i=0;i<=l+1;i++)
    //{
    //    cout<<a[i]<<" ";
    //}
    //cout<<endl;
    for (int i=1;i<l;i++)
    {
        if (i!=1&&(x==n||x==1)&&flag==1)
        {

            y++;
            flag=0;
            d=1-d;
        }
        else if (d==0)//down
        {
            x++;
            flag=1;
        }
        else
        {
            x--;
            flag=1;
        }
        q[x][y]=a[index];

        index--;
        //cout<<x<<" "<<y<<" "<<index<<endl;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            //cout<<q[i][j]<<" ";
            if (q[i][j]==r)
            {
                cout<<j<<" "<<i;

            }
        }
        //cout<<endl;
    }
    return 0;
}
