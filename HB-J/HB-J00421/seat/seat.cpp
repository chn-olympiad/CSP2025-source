#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x=1,y=1,maxn=-1,mina=101;
int main(){
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n*m;i++)
    {
     cin>>a[i];
     a[1];
    }
if(n==1&&m==1)
    {
    cout<<"1"<<" "<<"1";
    return 0;
    }
for(int i=1;i<=n*m;i++)
    {
    maxn=max(a[i],maxn);
    mina=min(a[i],mina);
    }
if(a[1]==maxn)
    {
    cout<<"1"<<" "<<"1";
    return 0;
    }
    if(a[1]==mina)
    {
    cout<<n<<" "<<m;
    return 0;
    }
    for(int i=2;i<=n*m;i++)
    {
    if(a[1]<a[i])
    {
        y++;
    }
    if(m<y)
    {
        y=y%m;
        if(x<2) y+=1;
        if(n>2) y--;
        x++;
        if(y==0) y++;

    }
    }
    cout<<x<<" "<<y;

return 0;
}
