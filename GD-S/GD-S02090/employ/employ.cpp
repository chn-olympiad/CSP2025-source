#include<bits/stdc++.h>
using namespace std;
#define fileio
#define IOS
void ___()
{
#ifdef fileio
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
#endif
#ifdef IOS
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    #define endl '\n'
#endif
}
#define ll long long
const int _mxn=500+5,_mod=998244353;
int n,m,s[_mxn],c[_mxn];
int p[_mxn];
int main()
{
    ___();
    cin>>n>>m;
    bool spa=true;
    for(int i=1;i<=n;i++)
    {
        char si;
        cin>>si;
        s[i]=si-'0';
        if(!s[i])
            spa=false;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        cin>>c[i],p[i]=i,cnt+=(c[i]>0);
    if(cnt==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(n<=10)
    {
        int ans=0;
        do
        {
            int gun=0,lu=0;
            for(int i=1;i<=n;i++)
            {
                if(gun>=c[p[i]])
                {
                    gun++;
                    continue;
                }
                if(s[i])
                    lu++;
                else
                    gun++;
            }
            if(lu>=m)
                ans++;
        }while(next_permutation(p+1,p+n+1));
        cout<<ans<<endl;
    }
    else
    {
        ll ans=1;
        for(int i=n;i>=1;i--)
            ans=ans*i%_mod;
        cout<<(cnt>0?ans:0)<<endl;
    }
    return 0;
}

/*
这个题数据范围有 c_i=0 是何意味，不想应聘就别来应聘（
*/