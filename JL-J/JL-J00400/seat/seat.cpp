#include <bits/stdc++.h>
using namespace std;
#define N 10010
int a[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int p;
    cin>>p;
    a[0]=p;
    for(int i=0;i<n;i++)
    {
        int a[i];
        cin>>a[i];
    }
    sort(a,a+n*m);
    for(int i=0;i<=n;i++)
    {
        a[i]++;
        a[i]=p;
    }

    cout<<p<<endl;
    return 0;
}
