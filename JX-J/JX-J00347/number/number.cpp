#include <iostream>
using namespace std;

string s;
int a[15],l;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++)
        if(s[i]<='9' and s[i]>='0')
            a[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=a[i];j++)
            cout<<i;
    return 0;
}
