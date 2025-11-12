#include<bits/stdc++.h>
using namespace std;
struct ren
{
    int num;
    int c;
}a[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,i;
    int b[505];
    char c;
    int s[505];
    int sum=0;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        cin>>c;
        a[i].num=i;
        s[i]=c-'0';
        sum+=s[i];
        b[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        cin>>a[i].c;
    }
    long long ans=0;
    if(sum==n)
    {
        cout<<0<<endl;
        return 0;
    }
    do
    {
        int cnt=0;
        for(i=1;i<=n;i++)
        {
            cnt++;
            if(cnt>=a[b[i]].c)
                continue;
            if(s[i]==1)
                cnt--;
        }
        if(n-cnt>=m)
        {
            ans++;
            ans%=998244353;
        }
    }
    while(next_permutation(b+1,b+n+1));
    cout<<ans<<endl;
    return 0;
}
