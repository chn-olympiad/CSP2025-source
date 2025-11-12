#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,k,ans=INT_MIN;
int x[N][N];
int main()
{
    memset(x,-1,sizeof(x));
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>x[1][i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            x[i][j]=x[i-1][j]^x[i-1][j+1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=n-1+i;j++)
        {
            if(x[i][j]==k) cnt++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
