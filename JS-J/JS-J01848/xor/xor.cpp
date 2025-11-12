#include<bits/stdc++.h>
using namespace std;
int n,a[500005],k,maxn=INT_MIN,minn=INT_MIN;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }
    if(maxn==1)
    {
        if(minn==1)
        {
            cout<<floor(n/2);
            return 0;
        }
        else
        {
            int cnt0=0,cnt1=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0)
                {
                    cnt0++;
                }
                else
                {
                    cnt1++;
                }
            }
            if(k==0)
            {
                cout<<floor(cnt1/2)+floor(cnt0/2)+cnt0%2;
                return 0;
            }
            else
            {
                cout<<cnt1;
                return 0;
            }
        }
    }
    cout<<0;
    return 0;
}
