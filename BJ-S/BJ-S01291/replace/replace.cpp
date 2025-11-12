#include <bits/stdc++.h>
using namespace std;

int a[222222];
string s[222222][3];
string t[222222][3];

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i][1]>>t[i][2];
        a[i]=(t[i][1].size()+t[i][2].size())/2;
        cout<<n-a[i]<<endl;
    }
    return 0;
}
