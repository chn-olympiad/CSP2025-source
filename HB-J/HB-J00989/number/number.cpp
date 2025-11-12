#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N],id=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if(isdigit(s[i]))
        {
            id++;
            a[id]=s[i]-'0';
        }
    }
    sort(a+1,a+1+id,cmp);
    for(int i=1;i<=id;i++)
        cout<<a[i];
    return 0;
}
