#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
int n,m,a,d;
cin>>n>>m;
int cnt=0;
for(int i=1;i<=n*m;i++)
{
cin>>a;
d=a;
if(d<a)
    {
    cnt++;
    }

}
int b=cnt/m;
int c=cnt%m;
if(cnt<=n)
{
    cout<<1<<" "<<cnt+1;
}
else
{
    cout<<b<<" "<<c;
}
return 0;
}
