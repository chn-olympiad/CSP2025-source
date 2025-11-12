#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int a[105],s,o,hang,lie;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==s)
        {
            o=i;
        }
    }
    lie=o/(2*n)*2;
    o=o-lie*n;
    if(o==0)
    {
        hang=1;
    }
    else if(o<=n)
    {
        hang=o;lie+=1;
    }
    else
    {
        if(o<=2*n)
        {
            lie+=2;hang=n-o%n+1;
        }
    }
    cout<<lie<<" "<<hang;
    return 0;
}
