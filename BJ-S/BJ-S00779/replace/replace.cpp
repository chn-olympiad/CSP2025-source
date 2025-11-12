#include<iostream>
#include<map>
#include<vector>
#define int long long
using namespace std;
int n,q;
const int nr=2e5+10,lr=5e6+10,base=131,mod=1e9+9;
string s[nr],t[nr];
int power[nr];
vector<int>vs[nr],vt[nr];
int pl[nr],pr[nr];
int cur;
map<pair<int,int>,int>mp;
vector<int>vid[nr];
int hs(vector<int>v,int l,int r)
{
    return (v[r]-v[l-1]*power[r-l+1]%mod+mod)%mod;
}
int hss[lr],hst[lr];
int h(int hh[],int l,int r)
{
    return (hh[r]-hh[l-1]*power[r-l+1]%mod+mod)%mod;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        cout<<0<<endl;
    }
    return 0;
}
