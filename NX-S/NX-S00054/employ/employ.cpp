#include <bits/stdc++.h>
#define int long long
using namespace std;
int nai[6000000];
const int MOD=998244353;
signed main()
{
    int n,m,ans=0;
    string s;
    cin>>n>>m;
    cin>>s;
    int ji=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')
        {
            ji=i;
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>nai[i];
        if(nai[i]>ji)ans++;
    }
    if(m==1)
    {
        //cout<<ji;
        int sum=0;
        int jia=1;
        for(int j=2;j<n;j++)
        {
            jia*=j;
            jia%=MOD;
        }
        for(int i=1;i<=ans;i++)
        {
            sum+=jia;
            sum%=MOD;
        }
        cout<<sum;
        return 0;
    }
    return 0;
}
