#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int cnt;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]<='9'&&a[i]>='0')
        {
            cnt++;
            b[cnt]=a[i]-'0';
        }
    }
    sort(b+1,b+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<b[i];
    }
    cout<<endl;
    return 0;
}
