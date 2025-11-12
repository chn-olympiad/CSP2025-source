#include<bits/stdc++.h>
using namespace std;
long long a[11][11];
long long b[101];
int main()
{
    long long n,m;
    cin>>n>>m;
    cin>>b[0];
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(b[i]>b[i+1])
            {
                int x;
                x=b[i];
                b[i]=b[i+1];
                x=b[i+1];
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(m%2==1)
            {
                a[i][j]=b[i];
            }
            else
            {
                cout<<a[i][j];
            }
        }
    }
}
