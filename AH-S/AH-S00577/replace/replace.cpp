#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("replace.in";"r";stdin);
    freopen("replace.out";"w";strout);
    int n,q;
    cin>>n>>q;
    string s[n+1][2],t[q+1][2];
    for(int i=1;i<=n;i++)
    {
        cin>>s[i][1]>>s[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>t[i][1]>>t[i][2];
    }
    for(int i=1;i<=q;i++)
    {
        for(int j=1;j<=t[i][1].size();j++)
        {
            if(t[i][1][j]==s[i][1]) replace(t[i][1],s[i][2],j,1);
        }
    }
    for(int i=1;i<=q;i++) cout<<"o"<<endl;
    return 0;
}
