#include <bits/stdc++.h>
using namespace std;
int b[1000005]={};
long long int n=0;
string a;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.length();++i)
    {
        if(a[i]<='9' && a[i]>='0')
        {
            b[i]=int(a[i])-48;
            ++n;
        }
    }
    sort(b,b+a.length()+5,cmp);
    for(int i=0;i<n;++i)
        cout<<b[i];
    return 0;
}
