#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0);
    long long tag[15]={0};
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            tag[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(tag[i]>=1)
        {
            tag[i]--;
            cout<<i;
        }
    }
    return 0;
}
