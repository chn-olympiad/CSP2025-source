#include<iostream>
using namespace std;
int s[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;

    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            s[a[i]-'0']++;
        }
    }

    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<s[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
