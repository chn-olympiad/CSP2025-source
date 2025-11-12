#include<bits/stdc++.h>
using namespace std;
int p[110];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;

    cin>>s;
    int l=s.size();
    for(int i=0;i<l;++i)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            p[s[i]-'0']+=1;
        }
    }
    for(int i=9;i>=0;--i)
    {
        while(p[i])
        {
            cout<<i;
            p[i]--;
        }
    }
    return 0;
}
