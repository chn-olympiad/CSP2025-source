#include<bits/stdc++.h>
using namespace std;
string s,s1;
int a,b[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9'){
                a=int(s[i]-48);
                b[a]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(b[i])
        {
            cout<<i;
            b[i]--;
        }
    }

    return 0;
}
