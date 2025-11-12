#include<bits/stdc++.h>
using namespace std;
string str;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    cin>>str;
    int cnt=0;
    int r=0;
    for(int i=1;i<=n;++i)
    {
        int c;
        cin>>c;
        if(c<=r) ++r;
    }
    long long x=1;
    for(int i=1;i<=n-r;++i)
    {
        x*=i;
        x%=998244353;
    }
    cout<<x<<endl;
    return 0;
}
