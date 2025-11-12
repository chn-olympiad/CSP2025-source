#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n,m;
string s;
int c[505];

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    bool flag;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(s[i-1]=='0')flag=false;
    }
    if(flag)
    {
        long long x=1;
        for(int i=1;i<=n;i++)
        {
            x=x*i*1ll;
            x%=998244353;
        }
        cout<<x<<endl;
        return 0;
    }

    return 0;
}
