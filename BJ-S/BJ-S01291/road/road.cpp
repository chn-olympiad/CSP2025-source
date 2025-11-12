#include <bits/stdc++.h>
using namespace std;

int a[1111111];
int c[1111111];
int u[1111111];
int v[1111111];
int w[1111111];

int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    cin>>c[1];
    for(int i=1;i<=m+1;i++)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum+=w[i];
    }
        cout<<2*sum/m;
    return 0;
}
