#include <iostream>

using namespace std;
int a[1010];
int b[1010];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b[1]=1;
    int f=0;
    for(int i=1;i<n*m;i++)
    {
        f=0;
        for(int j=1;j<n*m-i;j++)
        {
            if(a[j]<a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                if(b[j]==1)
                {
                    b[j]=0;
                    b[j+1]=1;
                }
                f=1;
            }
        }
        if(f==0)
        {
            break;
        }
    }
    int y=1;
    for(int i=1;i<=m;i++)
    {
        if(i%2!=0)
        {
            for(int j=1;j<=n;j++)
        {
            if(b[y]==1)
            {
                cout<<i<<" "<<j;
               return 0;
            }
            y++;
        }
        }
        else
        {
             for(int j=n;j>=1;j--)
        {
            if(b[y]==1)
            {
                cout<<i<<" "<<j;
               return 0;
            }
            y++;
        }
        }

    }

    return 0;
    //#Shang4Shan3Ruo6Shui4
}
