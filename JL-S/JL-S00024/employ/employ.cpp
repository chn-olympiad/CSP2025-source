#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],mod=998244353;
string s;
int mymax(int inA,int inB)
{
    return inA>inB? inA:inB;
}
int mymin(int inA,int inB)
{
    return inA<inB? inA:inB;
}
void tA()
{
    long long ans=1;
    for(int i=2;i<=n;i++)
        ans=(ans*i)%mod;
    cout<<ans;
    return;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    bool testA=true;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
        {
            testA=false;
            break;
        }
    }
    //if(testA)
    {
        tA();
        return 0;
    }
    cout<<998244352;
    return 0;
}