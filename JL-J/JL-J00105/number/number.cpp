#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int b[100001],t=1;
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            b[t] = a[i]-'0';
            t++;
        }
    }
    t--;
    sort(b+1,b+t+1);
    for(int i=t;i>=1;i--)
    {
        cout<<b[i];
    }
    return 0;
}
