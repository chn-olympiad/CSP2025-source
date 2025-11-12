#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    cout<<s;
    int maxx=0;
    for(int i=1;i<=10000000;i++)
    {
        if(s[i]==1 && s[i]==2 && s[i]==3 && s[i]==4 && s[i]==5 && s[i]==6 && s[i]==7 && s[i]==8 && s[i]==9)
        {
            int num=s[i];
            if(num>maxx)
            {
                cout<<num;
            }
        }
    }
}
