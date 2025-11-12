#include<bits/stdc++.h>
using namespace std;
string s;
long long k[1000005],l=1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            k[l]=(int)s[i]-48;
            l++;
        }
    }
    sort(k,k+l);
    for(int i=l-1;i>=1;i--)
        cout<<k[i];
    return 0;
}
