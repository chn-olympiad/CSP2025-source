#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int min=a[n/2];
    int x=a[1],y=a[1];
    for(int b=1;b<=n;b++)
    {
       for(int i=2;i<=min;i++)
        {
            x=x^a[i];
        }
        for(int j=min;j<=n;j++)
        {
            y=y^a[j];
        }
        if(x==y==k) cout<<k;
        else min=a[n/2-1];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
