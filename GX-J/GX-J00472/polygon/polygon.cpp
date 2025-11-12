#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt=0;
    cin >> n;
    int a[n+5];
    for(int i=1;i<=n;i++) cin >> a[i];
    if(a[1]+a[2]+a[3]>2*(max(a[1],max(a[2],a[3])))) cnt++;
    cout << cnt;
    return 0;
}
