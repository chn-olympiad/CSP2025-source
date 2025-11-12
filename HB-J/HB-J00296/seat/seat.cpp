#include <bits/stdc++.h>
using namespace std;
int n,s,z1,z2,z;
int a[1005],t[2];
int main()
{
    freopen("seat,in","r",stdin);
    freopen("seat,out","n",stdout);
    cin >> n >> s;
    int m=n*s;
    for(int i=1;i<=m;i++)
    {
        cin >> a[i];
    }
    t[1]=a[1];
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==t[1])
        {
            z=i;
            break;
        }
    }
    z1=z%n;
    z2=z/n;
    if(z2%2==1)
    {
        cout << s+1 << " " << n-z1;
    }
    else{
        cout << s+1 << " " << z1;
    }
    return 0;
}
