#include<bits/stdc++.h>
using namespace std;
char n[1000000];
int main()
{
    //freopen("number.in","r",stdin);
    //freopen("number.out","w",stdout);
    string x;
    int r=0;
    cin>>x;
    int u=x.size();
    for(int i=0;i<=u+1;i++)
    {
        if(x[i]<'a' || x[i]>'z')
        {
           n[i]=x[i];
           r+=1;
        }
    }
    sort(n,n+r);
    reverse(n,n+r);
    for(int i=0;i<=r;i++)
    {
        cout<<n[i];
;
    }
    return 0;
}
