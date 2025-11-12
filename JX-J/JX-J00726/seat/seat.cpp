#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,point,awa,qwq;
long long a[1000005];
long long check(long long mid,long long l,long long r)
{
    mid = (l+r)/2;
    if(a[mid] == point) return mid;
    else{
        if(a[mid] < point)
        {
            return check(mid,mid+1,r);
        }
        else{
            return check(mid,l,mid-1);
        }
    }
}
bool cmp(long long a,long long b)
{
    return a>b?true:false;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i == 1) point = a[i];
    }
    sort(a+1,a+1+n*m,cmp);
    for(long long i=1;i<=n*m;i++)
    {
        if(point == a[i])
        {
            if((i/(n+1)+1)%2 == 0){
                cout<<i/(n+1)+1<<" "<<n-i%(n+1);
            }
            else
            {
                cout<<i/(n+1)+1<<" "<<i%(n+1);
            }
        }
    }
    return 0;
}
