#include<bits/stdc++.h>
#include<cmath>
using namespace std;
long long ans=1;
int n,m;
string a;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int c;
    cin>>n>>m;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        cin>>c;
    }
    for(int i=n;i>=1;i--)
    {
        ans*=i;
        ans%=998244353;
    }
    cout<<ans%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
