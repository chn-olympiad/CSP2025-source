#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    int p=n*m;
    int q=0;
    int o=0;
    int nums=0;
    for(int i=1;i<=p;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            q=a[i];
        }
    }
    if(n==1&&m==1)
    {
        cout<<'1'<<" "<<'1';
    }
    else
    {
        sort(a+1,a+p+1);
        for(int i=1;i<=p;i++)
        {
            if(a[i]==q)
            {
                o=p-i+1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(nums>o)
            {
                break;
            }
            if(i%2==1)
            {
                for(int j=1;j<=n;j++)
                {
                    nums++;
                    if(nums==o)
                    {
                        cout<<i<<" "<<j;
                        break;
                    }
                }
            }
            else
            {
                for(int j=n;j>=1;j--)
                {
                    nums++;
                    if(nums==o)
                    {
                        cout<<i<<" "<<j;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
