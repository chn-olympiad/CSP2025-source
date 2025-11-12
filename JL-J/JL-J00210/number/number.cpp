#include<bits/stdc++.h>
using namespace std;
char s[1010000];
int a[1010000];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int l=strlen(s),n=0,x=0;
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9')
        {
            x=x+(int)s[i]-48;
            x=x*10;
            n++;
        }
    }
    x=x/10;
    int p=0;
    while(x!=0)
    {
        a[p]=x%10;
        x=x/10;
        p++;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
    {
        x=x+a[i];
        x=x*10;
    }
    x=x/10;
    cout<<x;
    return 0;
}
