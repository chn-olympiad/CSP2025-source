#include<bits/stdc++.h>
using namespace std;
const int N  = 1e6+10;
int c[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int j=1,k=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='1'&&s[i]<='9')
        {
            c[j] = s[i]-48;
            j++;
        }
        if(s[i]=='0')
        {
            k++;
        }
    }
   sort(c+1,c+j);
    for(int i=j-1;i>=1;i--)
{
    cout<<c[i];
}
for(int i=1;i<=k;i++)
{

    cout<<'0';
}
    return 0;
}
