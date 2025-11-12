#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[a.size()],g=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0' and a[i]<='9')
        {
            b[g]=a[i]-'0';
            g++;
        }
    }
    sort(b,b+g);
    for(int i=g-1;i>=0;i--)
        cout<<b[i];
    return 0;
}
