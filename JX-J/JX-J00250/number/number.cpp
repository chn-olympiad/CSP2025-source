#include <bits/stdc++.h>
#include <string>
using namespace std;
const int O = 100005;
char a[O];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i =1;i <=string.s();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[s[i]]++;
        }
    }
    for(int i ='9';i >='0';i++)
    {
        while(a[i]>0)
        {
            cout << i;
            a[i]--;
        }
        
    }
    return 0;
}
