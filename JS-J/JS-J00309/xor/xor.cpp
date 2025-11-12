#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll a[1000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(k==0)
    {
        int cnt=0;
        int tmp;
        bool m=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                cnt++;
                tmp=0;
                m=1;
            }
            else
            {
                if(m)
                {
                    tmp=a[i];
                    m=0;
                }
                else
                {
                    tmp^=a[i];
                }
                if(tmp==0)
                {
                    cnt++;
                    m=1;
                }
            }
        }
        cout<<cnt;
        return 0;
    }
    int cnt=0;
    int tmp;
    bool m=1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            cnt++;
            tmp=0;
            m=1;
        }
        else
        {
            if(m)
            {
                tmp=a[i];
                m=0;
            }
            else
            {
                tmp^=a[i];
            }
            if(tmp==k)
            {
                cnt++;
                m=1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
