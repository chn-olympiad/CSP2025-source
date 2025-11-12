#include <bits/stdc++.h>
using namespace std;

char a[555];
int c[555];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    int mul=1;
    for(int i=1;i<=n;i++)
    {
        if(c[i]!=0)
        {
            mul*=c[i];
        }
        else
        {
            mul+=c[i];
        }
    }
    cout<<mul%998244353;
    return 0;
}
