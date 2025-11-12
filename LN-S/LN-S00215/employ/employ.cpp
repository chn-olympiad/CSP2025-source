#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
int n,m,c[1000005];
bool flag;
string s;
long long cnt=1;
long long jc(int l)
{
    cnt=1;
    for(int i=1;i<=l;i++)
    {
        cnt*=i;
        cnt%=mo;
    }
    return cnt;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    cin>>m;
    cin>>s;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=0;i<n;i++)if(s[i]=='0')flag=1;
    if(!flag)
    {
        //cout<<jc(n)<<'\n'<<jc(m)<<'\n'<<jc(n-m)<<'\n';
        cout<<jc(n)/((jc(n-m)*jc(m))%mo)<<'\n';
    }
    else cout<<0;
    return 0;
}