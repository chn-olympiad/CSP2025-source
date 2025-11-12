#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
string s;
int a[N],zz;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9') a[zz]=s[i]-'0',zz++;
    sort(a,a+zz,cmp);
    for(int i=0;i<zz;i++)
        cout<<a[i];
    return 0;
}
