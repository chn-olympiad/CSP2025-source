#include<bits/stdc++.h>
using namespace std;
#define int    long long
const int mod=988244353;
int fact(int x)
{
    if(x<=1)return 1;
    return (x*fact(x-1))%mod;
}
int n,m;
bool s[1005];
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    int special_cnt=0;
    bool mark=1;
    for(int i=1;i<=n;i++)
    {
        char ch;
        cin>>ch;
        if(ch=='1')
        {
            s[i]=1;
            special_cnt++;
        }
        else mark=0;
    }
    if(mark)
    {
        cout<<(fact(special_cnt)*fact(m-special_cnt))%mod;
    }
    else if(m==1)
    {
        cout<<(special_cnt*fact(m-1))%mod;
    }
    return 0;
}
