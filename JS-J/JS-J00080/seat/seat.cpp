#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
    ll s=0,t=1;
    char c=getchar();
    while(c<'0'&&c>'9')
    {
        if(c=='-') t=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {

        s=s*10+c-'0';
        c=getchar();
    }
    return s*t;
}
bool cmp(ll a,ll b)
{

    return a>b;
}
ll n,m;
ll a[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n*m;i++) a[i]=read();
    ll _=a[1],id;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        //cout<<a[i]<<" ";
        if(a[i]==_) id=i;
    }
    //cout<<_<<endl;
    //cout<<id<<endl;
    ll y,x=(id-1)/n+1;
    if(x%2==1) y=(id%n==0)?n:id%n;
    else y=n-id%n+1;
    cout<<x<<" "<<y;
    return 0;
}
