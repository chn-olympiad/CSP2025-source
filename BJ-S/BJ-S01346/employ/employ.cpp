#include <iostream>
using namespace std;
int z,x,c,v;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>z>>x;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='1')c++;
    }
    v=c;
    for(int i=1;i<c;i++)
    {
        v*=i;
    }
    cout<<v;
    return 0;
}
