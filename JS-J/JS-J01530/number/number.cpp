#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int a[N];
int ai=1;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[ai]=(s[i]-'0');
            ai++;
        }
    }
    ai--;
    sort(a+1,a+1+ai,cmp);
    for(int i=1;i<=ai;i++)
    {
        cout<<a[i];
    }
    return 0;
}
