#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll cnt[30],n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    s=" "+s;
    n=s.length();
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9')cnt[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=cnt[i];j++)
            cout<<i;
    }
    return 0;
}
