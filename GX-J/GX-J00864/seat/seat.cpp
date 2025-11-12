#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,r,tj=1,c=0;
    cin>>n>>m;
    long long a[10000][10000],b[n*m];
    for(int i=0;i<n*m;i++)
    {
        cin>>b[i];
    }
    r=b[0];
    for(int i=0;i<n*m;i++)
    {
        for(int j=i+1;j<n*m;j++)
        {
            if(b[i]<b[j])
            {
                swap(b[i],b[j]);
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(tj%2!=0)
        {
            for(int j=0;j<n;j++)
            {
                a[j][i]=b[c];
            }
        }
        else if(tj%2==0)
        {
            for(int j=n-1;j>=0;j--)
            {
                a[j][i]=b[c];
            }
        }
        tj++;
        c++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==r)
            {
                cout<<j+1<<" "<<i+1;
                break;
            }
        }
    }
    return 0;
}
