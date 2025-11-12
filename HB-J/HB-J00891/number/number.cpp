#include<bits/stdc++.h>
using namespace std;
string s;
int a[100];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int as=int(s[i]-'0');
        if(0<=as && as<=9)
        {
            a[as]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i]!=0)
        {
            a[i]--;
            cout<<i;
        }
    }
    return 0;
}
