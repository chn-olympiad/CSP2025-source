#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int n,k;
int cnt=1,ans=-1;
bool f;
int dp[1000005];


int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>dp[i];
    }
    if(k==0)
    {
        for(int i=2;i<=n;i++)
        {
            if(dp[i]==dp[i-1]) cnt++;
            else {
                ans=max(cnt,ans);
                cnt=1;
            }

        }
        ans=max(cnt,ans);
    }
    cout<<ans<<endl;
    return 0;
}
