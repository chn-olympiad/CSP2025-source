#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int s2=0;
    int a[1000005];
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        char x=s[i];
        if(x>='1'&&x<='9')
        {
            s2++;
            a[s2]=x-'0';
        }
    }
    sort(a+1,a+s2+1);
    for(int i=1;i<=s2;i++)
    {
        cout<<a[i];
    }
    return 0;
}
