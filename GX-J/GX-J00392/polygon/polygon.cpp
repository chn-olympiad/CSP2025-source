#include<bits/stdc++.h>
using namespace std;
int main()
{
    feopen("polygon.in","r",stdin);
    feopen("polygon.out","w",stdout);
    int n,x=0,num=0;
    cin>>n;
    int a[10000];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>x)
        {
            x=a[i];
        }
    }
    for(int i=3;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {

        }
    }
    return 0;
}
