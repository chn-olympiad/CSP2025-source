#include <bits/stdc++.h>
using namespace std;

int a[5001];
long long ans=0;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >>n;
    for(int i=1; i<=n; i++)
    {
        cin >>a[i];
    }
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2)
        {
            ans++;
        }
        cout <<ans;
    }
    return 0;
}
