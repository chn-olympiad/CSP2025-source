#include<bits/stdc++.h>
using namespace std;
int cmp(string a,string b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    string c[100005];
    string ans;
    cin>>s;
    int t=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            t++;
            c[t]=s[i];
        }
    }
    sort(c+1,c+t+1,cmp);
    for(int i=1;i<=t;i++)
    {
        cout<<c[i];
    }

    return 0;
}
