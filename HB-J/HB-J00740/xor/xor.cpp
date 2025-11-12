#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,a[N],k,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    int q=1;
    while(1)
    {
        int w=0;
        if(q>=n)
        {
            break;
        }
        int i;
        for(i=q;i<=n;++i)
        {
            w=(w xor a[i]);
            if(w==k)
            {
                ++ans;
                break;
            }
        }
        q=i+1;
    }
    cout<<ans;
    return 0;
}
