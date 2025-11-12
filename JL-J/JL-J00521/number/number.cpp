#include <iostream>
#include <ios>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s, a="";
    cin>>s;
    while(!s.empty())
    {
        char m='0';
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]<'0'||s[i]>'9')
            {
                s.erase(s.begin()+i);
                i--;
            }
            else if(s[i]>m)
            {
                m=s[i];
                j=i;
            }
        }
        a.push_back(m);
        m='0';
        s.erase(s.begin()+j);
        j=0;
    }
    cout<<a;
    return 0;
}
