#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[21],S[21],t[21],T[21];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>s[i]>>S[i];
    for(int j=1;j<=m;j++)
    {
        cin>>t[j]>>T[j];
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int l=0;l+s[i].size()-1<t[j].size();l++)
            {
                string a,b;
                for(int k=0;k<l;k++) a+=t[j][k];
                for(int k=0;k<s[i].size();k++) if(s[i][k]==t[j][l+k]) a+=S[i][k];
                for(int k=l+s[i].size();k<t[j].size();k++) a+=t[j][k];
                if(a==T[j]) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}