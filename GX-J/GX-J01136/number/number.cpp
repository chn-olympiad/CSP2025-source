#include<bits/stdc++.h>
using namespace std;
long long w[1000001];
int main()
{
    string s;
    cin>>s;
    int r=1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<=9)
        {
            w[i]=s[i]-'0';
            r++;
        }
    }
    int y=0;
    for(int i=1;i<=r;i++)
    {
        if(w!=0)y++;
    }
    if(y==0)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=r;i++)
    {
        for(int j=i;j<=r-1;j++)
        {
            if(w[j]<w[j+1])swap(w[j],w[j+1]);
        }
    }
    for(int i=1;i<=r;i++)
    {
        cout<<w[i];
    }
    return 0;
}
