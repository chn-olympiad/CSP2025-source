#include<bits/stdc++.h>

using namespace std;
bool mycmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int n[1000005];
    int j=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>=0)
        {
            n[j]=s[i]-'0';
            j++;
        }
    }
    sort(n,n+j,mycmp);
    for(int i=0;i<j;i++)
    {
        cout<<n[i];
    }
    return 0;
}
