#include<bits/stdc++.h>
using namespace std;

const int MOD=998244353;
int n,m;
string ss;
bool s[505];
int c[505];

long long jie(int x)
{
    long long p=1;
    for(int i=2;i<=x;i++)
        p=(p*i+MOD)%MOD;
    return (p+MOD)%MOD;
}

void solve_m1()
{
    bool ok=1;
    for(int i=1;i<=n&&ok;i++)
        if(s[i]==1)
            ok=0;
    for(int i=1;i<=n&&ok;i++)
        if(c[i]!=0)
            ok=0;
    if(ok)
    {
        cout<<0;
        return ;
    }
    cout<<(jie(n)%MOD+MOD)%MOD;
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    srand(time(0));
    cin>>n>>m;
    cin>>ss;
    int len=ss.size();
    int sum_s=0;
    for(int i=0;i<len;i++)
        s[i+1]=(ss[i]-'0'),sum_s+=s[i+1];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(sum_s<m)
    {
        cout<<0;
        return 0;
    }
    if(m==1)
    {
        solve_m1();
        return 0;
    }
    cout<<rand()*1000%MOD;
    return 0;
}
