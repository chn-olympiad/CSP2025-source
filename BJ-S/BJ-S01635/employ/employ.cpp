#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
const int N=505;
int a[N];
int c[N];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n==m)
    {
        bool flag=true;
        for(int i=0;i<s.size();i++) flag&=(s[i]=='1');
        for(int i=1;i<=n;i++) flag&=c[i];
        if(flag)
        {
            int ans=1;
            for(int i=1;i<=n;i++) ans=ans*i%Mod;
            cout<<ans;
        }
        else cout<<0;
        return 0;
    }

    for(int i=1;i<=n;i++) a[i]=i;
    int ans=0;
    do
    {
        int cnt=0;
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=c[a[i]])
            {
                cnt++;
                continue;
            }
            if(s[i-1]=='0') cnt++;
            else sum++;
        }
        //for(int i=1;i<=n;i++) cout<<a[i]<<" ";
        //cout<<cnt<<" "<<sum<<endl;
        ans+=(sum>=m);
    }while(next_permutation(a+1,a+n+1));
    cout<<ans;
    return 0;
}
