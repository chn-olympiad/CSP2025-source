#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
string s;
char x[N];
signed main()
{
     freopen("number4.in", "r", stdin);
    // freopen("number.out", "w", stdout);
    cin>>s;
    int len =s.size();
    for(int i=0;i<len;i++)
    {
        if(s[i]<'a')
        {
            x[i]=s[i];
        }
       // cout<<x[i];
    }
    sort(x, x+len);
    for(int i=len-1;i>=0;i--)
    {
        cout<<x[i];
    }
    return 0;
}
