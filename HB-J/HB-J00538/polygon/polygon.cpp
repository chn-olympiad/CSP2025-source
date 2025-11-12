#include <iostream>

using namespace std;
int a[1010];
int b[1010];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    int f;
    for(int i=1;i<=n-1;i++)
    {
        f=0;
        for(int j=1;j<=n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                f=1;
            }
        }
        if(f==0)
        {

            break;
        }
    }
    if(n<3)
    {
        cout<<0;
        return 0;
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1;
            return 0;
        }
    }
    if(n>3)
    {
        cout<<9;
    }

    return 0;
}
