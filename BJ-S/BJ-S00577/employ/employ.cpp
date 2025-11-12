#include<bits/stdc++.h>
using namespace std;
const int MO=998244353;
long long ans=1;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int m,n,s[507];
    char j[511];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char q;
        cin>>q;
        if(q=='0')
        {
            cout<<0<<endl;
            return 0;
        }
    }
    for(int z=1;z<=n;z++)
    {
        cin>>s[z];
    }


        for(int y=1;y<=n;y++)
        {
            if(s[y]==0)
            {
                cout<<0<<endl;
                return 0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=MO;
        }
        cout<<ans<<endl;
        return 0;

    cout<<0<<endl;
    return 0;
}
//rp++;
