#include<bits/stdc++.h>
using namespace std;
char a;
int b[1000000],c;
int main(void)
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while(cin>>a)
    {
        if(a>='0'&&a<='9')
        {
            b[c]=a-'0';
            c++;
        }
    }
    sort(b,b+c);
    for(int i=c-1;i>=0;i--)
        cout<<b[i];
    return 0;
}
