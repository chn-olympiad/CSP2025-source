#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long ll;
string s;
int ed,a[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[++ed]=s[i]-'0';
        }
    }
    sort(a+1,a+ed+1);
    for(int i=ed;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
