#include<bits/stdc++.h>
using namespace std;
constexpr int N=5007;
int a[N];
int ans;
int n;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    if(n==3)
    {
        if(a[1]+a[2]+a[3]>max({a[1},a[2],a[3])*2)
        {
            cout << 1;
        }else
            cout <<0;
    }else if(n<3)
    {
        cout << 0;
    }
    return 0;
}
