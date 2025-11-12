#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>v(n*m);
    for(int i=0;i<n*m;i++)cin>>v[i];
    int R=v[0];
    sort(v.begin(),v.end());
    int seat[n][m];
    int k=n*m-1;
    for(int j=0;j<m;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<n;i++)
            {
                seat[i][j]=v[k];
                k--;
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                seat[i][j]=v[k];
                k--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(seat[i][j]==R)
            {
                cout<<j+1<<" "<<i+1;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
