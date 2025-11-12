#include<bits/stdc++.h>
using namespace std;

int n,m,a,x,c=1,r=1;

int main()
{
    cin>>n>>m;
    int s[n*m+5];
    for(int i=1;i<=n*m;++i)
    {
        cin>>s[i];
    }
    a=s[1];
    sort(s,s+n*m);
    for(int i=1;i<=n*m;++i)
        if(a==s[i])
            x=i;
    while(x>n)
    {
        x-=n;
        c++;
    }
    if(c%2==0)
        r=n-x+1;
    else
        r=x;
    cout<<c<<" "<<r;

    return 0;
}
