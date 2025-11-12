#include<bits/stdc++.h>
using namespace std;
char c;
int a[1000006];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    #if 1
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    #endif
    int dot=0;
    while(cin>>c)
    {
        if(c>='0' && c<='9')
        {
            dot++;
            a[dot]=c-'0';
        }
    }
    sort(a+1,a+dot+1,cmp);
    for(int i=1;i<=dot;i++)
    {
        cout<<a[i];
    }
    return 0;
}
