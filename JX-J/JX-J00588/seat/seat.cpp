#include<bits/stdc++.h>
using namespace std;
long long n,m,c,r,x,y,a[105],cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1) x=a[i];
    }
    sort(a+1,a+1+n*m);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==x) y=i;
    }
    cnt=n*m-y+1;
    if(cnt%m==0)
    {
        c=cnt/m;
        if(c%2!=0)
        {
            r=m;
        }
        else
        {
            r=1;
        }
    }
    else
    {
        c=cnt/m+1;
        if(c%2!=0)
        {
            r=cnt%m;
        }
        else
        {
            r=m-cnt%m+1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
