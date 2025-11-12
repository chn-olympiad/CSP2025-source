#include<iostream>
using namespace std;
int main()
{
    freopen;{"number.in","r";stdin;}
    freopen;{"number.out","r";stdin;}
    string s;
    cin>>s;
    string p;
    int f[s.size()];
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i] && s[i]<='9')
        {
            int a=s[i];
            f[i]=a;
        }
    }
    for(int i=0;i<s.size()-1;i++)
    {
        cout<<f[i]<<" ";
    }
    return 0;
}
