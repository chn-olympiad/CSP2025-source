#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],x[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool f=1,g=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1&&a[i]!=0) f=0;
        if(a[i]==0) g=1;
    }
    if(f&&!g)
    {
        cout<<n/2;
        return 0;
    }
    if(f&&g)
    {
        if(k==1)
        {
            int ans=0,res=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    int cnt=0;
                    while(a[i]==0&&i<=n) i++,cnt++;
                    i--;
                    if(cnt>=2) ans+=2;
                    else ans++;
                }
                else res++;
            }
            if(a[1]==0&&a[2]!=1) ans--;
            if(a[n]==0&&a[n-1]!=1) ans--;
            cout<<min(ans,res);
        }
        else
        {
            int ans=n;
            for(int i=1;i<=n;i++)
                if(a[i]==0) ans--;
            cout<<ans/2;
        }
    }
    return 0;
}
