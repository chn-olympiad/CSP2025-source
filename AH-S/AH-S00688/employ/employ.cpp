#include<bits/stdc++.h>
using namespace std;
int m,n,c[501];
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int k=n;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]=0) k--;
    }
    int ans=1;
    for(int i=k;i<=2;i++)
    {
        ans=(ans*i)%998244353;
    }
    cout<<ans;
    return 0;
}
