#include <bits/stdc++.h>
using namespace std;
const int set1=150,set2=15;
int a[set1],b[set2],c[set1];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=m*n;i++)
    for (int j=1;j<=m*n;j++)
    {
        if (a[j]<=a[i])
            swap(a[i],a[j]);
    }
    for (int i=1;i<=m;++i)
    {
        a[i]++;
    }
    cout<<a;
    return 0;
}
