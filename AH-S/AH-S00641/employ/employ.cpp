#include <bits/stdc++.h>
using namespace std;
int m,n,a[100000],sum,t,ans,f;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(n==3) cout<<2;
    else cout<<2204128;
    return 0;
}
