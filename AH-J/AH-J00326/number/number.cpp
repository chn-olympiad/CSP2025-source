#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool cmp(const ll &x,const ll &y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    ll ans=0;
    ll a[1000000];
    for(ll i=0;i<=s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[i]=s[i];
            ans++;
        }
    }
    sort(a+1,a+ans+1,cmp);
    for(ll i=1;i<=ans;i++)cout<<a[i];
    return 0;
}
