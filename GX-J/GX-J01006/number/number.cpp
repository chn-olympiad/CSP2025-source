#include<bits/stdc++.h>
using namespace std;
long long b[1000005]={-1};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    char t;
    long long c=0;
    for(long long i=0;i<a.size();i++)
    {
        t=a[i];
        if(t>='0'&&t<='9')
        {
            t-='0';
            c++;
            b[c]=t;
        }
        char(t);
    }
    sort(b+1,b+a.size()+1);
    int u=0;
    for(long long i=a.size();i>=1;i--)
    {
        cout<<b[i];
        u++;
        if(u==c)return 0;
    }
    return 0;
}
