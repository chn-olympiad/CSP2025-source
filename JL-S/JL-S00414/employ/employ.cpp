#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
const ll N=505;
ll s[N];
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(m==n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            if(s[i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        cout<<1;
    }
    else
    {
        bool f=1;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            if(s[i]=0)
                f=0;
        }
        if(f)
        {
            cout<<1;
            return 0;
        }
    }
    return 0;
}
