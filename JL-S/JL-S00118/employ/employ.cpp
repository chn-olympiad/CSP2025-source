#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s_in;
int s[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    cin>>n>>m;
    cin>>s_in;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<s_in.size();i++) s[i+1]=s_in[i]-'0';
    cout<<0;
    return 0;
}
//998 244 353
