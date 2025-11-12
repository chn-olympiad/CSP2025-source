#include<bits/stdc++.h>
using namespace std;
int main()
{
    feopen("seat.in","r",stdin);
    feopen("seat.out","w",stdout);
    int n=0,m=0;
    int a[1000];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int b=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i;j<=n*m;j++)
        {
            if(a[i]<a[j])
            {
                int y;
                y=a[i];
                a[i]=a[j];
                a[j]=y;
            }
        }
    }
    int l=1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[l]==b)
            {
                cout<<i<<" ";
                if(i%2==0)
                {
                    int e=1;
                    for(int f=n;f>=1;f--)
                    {
                        if(e==j)
                        {
                            cout<<f;
                            break;
                        }
                        e++;
                    }
                }
                else
                {
                    cout<<j<<" ";
                }
            }
            l++;
        }
    }
    return 0;
}
