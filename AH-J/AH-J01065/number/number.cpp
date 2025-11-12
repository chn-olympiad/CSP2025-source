#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+10;
map<ll,ll> m;
ll a[15];
//ll a[N],len;
string s;
bool cmp(ll x,ll y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    /*for(ll i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            len++;
            a[len]=s[i]-'0';
        }
    }
    sort(a+1,a+1+len,cmp);
    for(ll i=1;i<=len;i++)cout<<a[i];
    */
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            m[s[i]-'0']=s[i]-'0';
            a[s[i]-'0']++;
        }
    }
    for(auto it=m.end();it!=m.begin();it--)
    {
        if(it->second!=0)for(ll i=0;i<a[it->second];i++)cout<<it->second;
    }
    for(ll i=1;i<=a[0];i++)cout<<0;
    return 0;
}
//0u050hz08t2ibm70y4exp04u6m44838cont753674e569zh6hpkxr9tyd0l1odacalb5u0a835e7631x9581dy8pnui496e7t0bx
