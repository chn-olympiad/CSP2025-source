#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int s[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,m,k=1,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]^=s[i-1];
    }
    while(1)
    {
        bool b=1;
        for(int i=k;i<=n;i=-(~i))
        {
            for(int j=k;j<=i;j=-(~j))
            {
                if((s[i]^s[j-1])==m)
                {
                    k=i+1;
                    ans++;
                    b=0;
                    break;
                }
            }
            if(!b)
            {
                break;
            }
        }
        if(b)
        {
            break;
        }
    }
    cout<<ans;
    return 0;
}
