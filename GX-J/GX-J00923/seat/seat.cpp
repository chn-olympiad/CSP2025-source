#include<bits/stdc++.h>
using namespace std;
long long a[201];
bool px(long long a,long long b)
{
    return a>b;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
long long n,m;
cin>>n>>m;
long long rs=n*m,pm=0;
for(int i=1;i<=rs;i++)cin>>a[i];
long long fs=a[1];
sort(a+1,a+1+rs,px);
for(int i=1;i<=rs;i++)
    {
        if(a[i]==fs)pm=i;
    }

long long l=0,h=0,ys=0;
ys=pm%n;
if(ys==0)l=pm/n;
else
    {
        l=(pm-ys)/n+1;
    }
cout<<l<<" ";

if(l%2==1)
    {
        if(pm%n==0)h=n;
        else h=pm%n;
    }
else
    {
        if(pm%n==0)h=1;
        else h=1+n-pm%n;

    }
    cout<<h;
return 0;
}


