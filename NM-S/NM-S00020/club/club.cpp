#include<bits/stdc++.h>
using namespace std;


int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t;
    cin >> t;
    int n;
    int myd[100000][1000000];

    for(int i=1;i<=t;i++)
    {
        cin >> n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin >> myd[i][j];
            }
        }
    }

    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            if(myd[i][j]<myd[i+1][j] || myd[i][j]<myd[i][j+1])
            {
                swap(myd[i][j],myd[i+1][j]);
                swap(myd[i][j]<myd[i][j+1]);
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            int sum = myd[i][j];
        }
    }
    cout << myd;
    return 0;
}