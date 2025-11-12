#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool q(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int w=0;
    for(int i=0;i<s.size();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[w]=s[i]-'0';
            w++;
        }
    }
    sort(a,a+w,q);
    for(int i=0;i<w;i++)
    {
        cout<<a[i];
    }
    return 0;
}
