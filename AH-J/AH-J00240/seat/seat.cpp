#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000+5],b,cnt,c,d;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    b=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)if(a[i]==b)cnt=i;
    for(int i=1;;i++)
    {
        if(i*n>cnt)
        {
            cout<<i<<" ";
            if(i%2==1)cout<<cnt-(i-1)*n;
            else cout<<n-(cnt-(i-1)*n)+1;
            return 0;
        }
        else if(i*n==cnt)
        {
            cout<<i<<" "<<n;
            return 0;
        }
    }
    return 0;
}
