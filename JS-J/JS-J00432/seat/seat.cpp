#include<bits/stdc++.h>
using namespace std;
int n,m,b[101];
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int tm=0;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int k=b[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m;j++)
        {
            if(b[i]>b[j])
            {
                swap(b[i],b[j]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            for(int j=1;j<=m;j++)
            {
                tm++;
                if(b[tm]==k)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else
        {
            for(int j=m;j>=1;j--)
            {
                tm++;
                if(b[tm]==k)
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
