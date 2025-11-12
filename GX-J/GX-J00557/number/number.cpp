#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
ll num[101];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    //ios::sync_with_stdio(false);
    cin>>s;
    for(ll i=0; i<s.size(); i++)
        if('0'<=s[i]&&s[i]<='9')
            num[s[i]-'0']++;
    for(ll i=9; i>=0; i--)
        for(ll j=1; j<=num[i]; j++)
            printf("%lld",i);
    return 0;
}
