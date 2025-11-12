# include<cstdio>
# include<iostream>
# include<algorithm>
using namespace std;
int n,k,a[500005],s[500005],dp[500005],m[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i<=n;i++)
    {
        cin >> a[i];
        s[i] = a[i] ^ s[i-1];
    }
    for(int i = 1;i<=n;i++)
    {
        dp[i] = 0;
        for(int j = 0;j<i;j++)
        {
            int now = 0;
            /*for(int x = j+1;x<=i;x++)
            {
                now = now^a[x];
            }*/
            now = s[i] ^ s[j];
            if(now == k)
            {
                dp[i] = max(dp[i],m[j]+1);
            }
        }
        m[i] = max(m[i-1],dp[i]);
    }
    /*for(int i = 1;i<=n;i++)
    {
        printf("%d ",s[i]);
    }
    printf("\n");
    for(int i = 1;i<=n;i++)
    {
        printf("%d ",dp[i]);
    }*/
    printf("%d",m[n]);
    return 0;
}
