#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char a[1111111];
    cin>>a;
    int b[1111111],n,o=0;
    n=strlen(a);
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
            {b[o]=a[i]-48;o++;}
    }
    sort(b,b+o);
    for(int i=o-1;i>=0;i--)
    {
        cout<<b[i];
    }
    return 0;
}
