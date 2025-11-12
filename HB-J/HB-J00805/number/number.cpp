#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int cnt=0;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<int(a.size());i++)
    {
        if(isdigit(a[i]))
            b[++cnt]=int(a[i]-'0');
    }
    sort(b+1,b+1+cnt,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<b[i];
    }
    return 0;
}
