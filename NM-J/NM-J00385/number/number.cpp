#include <bits/stdc++.h>
using namespace std;
long long n,s,d,b[100000];
char a[100000];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(n=s=0;n<strlen(a);n++)
    {
        if(a[n]>='0' and a[n]<='9')
         b[s++]=int(a[n]-'0');
    }
    sort(b,b+s,cmp);
    for(n=d=0;n<s;n++)
    {
        d=d*10+b[n];
    }
    cout<<d<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
