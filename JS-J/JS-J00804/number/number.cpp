#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000007;
string s;
int n;
int ans[20];
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=ans[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
//bu4 gei3 zhong1 wen2 shu1 ru4 fa3 qi4 si3 wo3 le4
//Will I AFO
//I don't want to whk
