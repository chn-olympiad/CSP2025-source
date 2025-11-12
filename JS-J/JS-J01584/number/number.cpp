#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
string s;
priority_queue<ll>a;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>s;
    for(int i=0; i<s.size(); i++)
    {
        char c=s[i];
        if(c>='0' && c<='9')
        {
            a.push((ll)(c-'0'));
        }
    }
    while(!a.empty())
    {
        cout<<a.top();
        a.pop();
    }
    return 0;
}
