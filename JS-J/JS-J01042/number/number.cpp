#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int lens=s.size(),l[1000005]={0},cnt=0;
    for(int i=0;i<lens;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            l[cnt]=int(s[i])-48;
            cnt++;
        }
    }
    sort(l,l+cnt);
    for(int i=cnt-1;i>=0;i--) cout<<l[i];
    return 0;
}
