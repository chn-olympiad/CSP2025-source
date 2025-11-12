#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int read()
{
    int x=0,f=1;
    char c;
    c=getchar();
    while((c<'0'||c>'9')&&c!='-')   c=getchar();
    if(c=='-')
    {
        f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    int a[15]={};
    string s;
    cin>>s;
    int l=s.size();
    for(int i=0;i<l;i++)
    {
        if('0'<=s[i]&&s[i]<='9')    a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        while(a[i]--) cout<<i;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
