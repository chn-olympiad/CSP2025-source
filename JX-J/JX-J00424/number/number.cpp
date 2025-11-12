#include<bits/stdc++.h>
using namespace std;
string s,num[10000006];
int x=0;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size()-1;
    for(int i=0;i<=len;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            x++;
            num[x]=s[i];
        }
    }
    sort(num+1,num+x+1);
    for(int i=x;i>=1;i--) cout<<num[i];
    return 0;
}
