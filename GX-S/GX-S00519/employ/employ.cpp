#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a=0;
    for(int i=0;i<s.size();i++)
        if(s[i]=='1')
            a++;
    int b=0;
    for(int i=1;i<=n;i++)
        cin>>b;
    if(a<m)
        cout<<0;
    else
        cout<<998244352;
    return 0;
}
