#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<i<<' '<<j<<endl;
        }
    }
}
