#include<bits/stdc++.h>
using namespace std;
string s;
const int N=10e6+10;
int a[N];
int tail;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            a[++tail]=s[i]-'0';
    }

    sort(a+1,a+1+tail);
    for(int i=tail;i>=1;i--)
        cout<<a[i];
    return 0;
}

