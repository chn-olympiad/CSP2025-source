#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char s[1010];
    cin>>s;
    int a[10]={0},c=0;
    for(int i=0;i<strlen(s);i++)
    {
        int b=int(s[i])-48;
        if(b>=0 && b<10)
        {
            a[b]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        if(a[i]>0)
        {
            c=(c+i)*10;
        }
    }
    cout<<c/10;

    return 0;
}
