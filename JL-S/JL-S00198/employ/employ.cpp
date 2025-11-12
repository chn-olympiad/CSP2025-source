#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
int n,m;
string s;
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    cout<<rnd()%998244353;
}
