#include<bits/stdc++.h>
using namespace std;
int t[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i;
    string s;
    cin>>s;
    for(i=0;i<s.size();i++)
    {
        if(!(s[i]>='0'&&s[i]<='9'))
            continue;
        int n;
        n=s[i]-'0';
        t[n]++;
    }
    for(i=10;i>=0;i--)
    {
        if(t[i]==0)
            continue;
        for(int j=1;j<=t[i];j++)
            cout<<i;
    }
    cout<<endl;
    return 0;
}
