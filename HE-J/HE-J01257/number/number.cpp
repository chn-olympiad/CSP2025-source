#include <iostream>
#include <algorithm>
using namespace std;
int c[1000005];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string m,n;
    cin>>m;
    for(int i=0;i<m.length();i++)
    {
        if(m[i]<='9'&&m[i]>='0')
        {
            n+=m[i];
        }
    }
    for(int i=0;i<n.length();i++)
    {
          c[i]=n[i]-'0';
    }
    sort(c,c+n.length());
    for(int i=n.length()-1;i>=0;i--)
    {
        cout<<c[i];
    }
}
