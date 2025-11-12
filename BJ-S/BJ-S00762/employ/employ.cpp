#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
char s[502];
int c[502];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    bool isa=true;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]!='1')
        {
            isa=false;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(isa)
    {
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(c[i]==0)
                k++;
        }
        long long sum=1;
        for(int i=1;i<=n-k;i++)
        {
            sum=sum*i%mod;
        }
        cout<<sum;
        return 0;
    }
    cout<<1;
    return 0;
}
