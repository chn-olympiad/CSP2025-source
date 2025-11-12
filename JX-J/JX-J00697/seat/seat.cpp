#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    long long a[100000],b[100000];
    int x=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
            cin>>a[i];
            b[i]=a[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m-1;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    x=0;
    for(int i=1;i<=m;i++)
    {
            if(i%2!=0)
            {
                for(int j=1;j<=n;j++)
                {
                    x++;
                    if(a[x]==b[1])
                    {
                        cout<<i<<" "<<j<<endl;
                        return 0;
                    }
                }
            }
            else
            for(int j=n;j>=1;j--)
            {
                x++;
                if(a[x]==b[1])
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
    }
    return 0;
}
