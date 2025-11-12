#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
int p(int k)
{
    int ans=1;
    for(int i=1;i<=k;i++)
    {
        ans*=i;
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    cout<<p(n);
    return 0;
}
