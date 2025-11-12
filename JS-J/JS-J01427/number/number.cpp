#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const int MAXN=0;
int main ()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    vector<int> v;
    cin>>s;
    fore(i,0,s.size())
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            v.pb(s[i]-'0');
            
        }
    }
    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i];
    }
    return 0;
}
