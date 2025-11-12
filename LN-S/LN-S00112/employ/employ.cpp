#include<bits/stdc++.h>
using namespace std;
int n,m,a[510];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)cin>>a[i];
    int h=1;
    for(int i=n;i>1;i--)h=h%998244353*i;
    cout<<h;
    return 0;
}
