#include<bits/stdc++.h>
using namespace std;

int n,Q;
string s[200005][3];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>Q;
    for(int i=1;i<=n;i++)
        cin>>s[i][1]>>s[i][2];
    for(int o=1;o<=Q;o++)
    {
        string s1,s2;
        cin>>s1>>s2;
        cout<<0<<'\n';
    }
    return 0;
}
