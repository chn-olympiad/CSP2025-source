#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=507;
const ll MOD=998244353;
const int INF=0x3f3f3f3f;
//time :O(N2)
//space:O(N2)
int T;
int n,m;
string s;
ll cnt_s;
ll a[N];
ll fact[N];
bool v[N]={0};
bool spec_kind=1;

ll dfs(ll now, ll day, ll gone);

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("employ.in" ,"r",stdin );
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s="1"+s;
    fact[0]=1;
    a[0]=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fact[i]=(fact[i-1]*i)%MOD;
        //cout<<fact[i]<<"\n";
        if(s[i]=='0')spec_kind=0;
        if(a[i]==0)spec_kind=0;
        if(s[i]=='1')++cnt_s;
    }
    if(cnt_s<m){cout<<"0\n";return 0;}
    if(spec_kind)
    {
        cout<<fact[n]<<"\n";
        return 0;
    }
    cout<<dfs(0,0,0)<<"\n";
    return 0;
}

ll dfs(ll now, ll day, ll gone)
{
    //cout<<" day"<<day<<":"<<now<<" ";
    if(day>=n and gone+(ll)(s[day]=='0' or gone>=a[now])<=n-m)return 1;
    //cout<<" rock ";
    if(gone>n-m)return 0;
    //cout<<" "<<gone<<" ";
    if(day-gone>m)return fact[n-day];
    ll ans=0;
    v[now]=1;
    //cout<<gone;
    for(int i=1;i<=n;++i)
    {
        if(v[i])continue;
        //cout<<" babe\n";
        ans+=dfs(i,day+1,gone+(ll)(s[day]=='0' or gone>=a[now]));
        ans%=MOD;
    }
    v[now]=0;

    return ans;
}

/*
=====TODO=====
subtest init
long long
freopen triple chaeck
cornercase
g++ lmz.cpp -o lmz -Wall
estimate time and space
rp++
save before run

*/
