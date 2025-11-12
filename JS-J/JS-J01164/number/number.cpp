#include<bits/stdc++.h>
using namespace std;
string s;
int l[11],k;
int main()
{
   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    k=s.size();
    for(int i=0;i<k;i++)
    {
        if(int(s[i])>=48&&int(s[i])<=57)
        {
            int c=int(s[i])-48;
            l[c]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=l[i];j++)cout<<i;
    }
}
