#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005],j;
string s,x;
bool cmp(ll w,ll e)
{
    return w>e;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(ll i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9') a[++j]=s[i]-'0';
    sort(a+1,a+j+1,cmp);
    for(ll i=1;i<=j;i++)
        x+=a[i]+'0';
    cout<<x;
    return 0;
}
