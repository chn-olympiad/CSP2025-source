#include <bits/stdc++.h>
using namespace std;
int n,a[5005],sum,num,maxn;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];

    }
    int t=0;
    for(int i=3;i<=n;i++)
    {
        t=0;
        for(int j=i;j<=i+i;j++)
        {
            t++;
