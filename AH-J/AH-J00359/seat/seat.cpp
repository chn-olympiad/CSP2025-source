#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[15][15],x=1,y=1,way,pos=1,num;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int k=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    while (1)
    {
        if (way==0)
        {
            for (int i=1;i<=n;i++)
            {
                b[x][y]=a[pos];
                pos++;
                x=min(n,x+1);
                num++;
            }
            y=min(m,y+1);
        }
        else
        {
            for (int i=1;i<=n;i++)
            {
                b[x][y]=a[pos];
                pos++;
                x=max(x-1,1);
                num++;
            }
            y=min(m,y+1);
        }
        if (way==0) way=1;
        else way=0;
        if (num==n*m)
        {
            break;
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (b[i][j]==k)
            {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    return 0;
}
