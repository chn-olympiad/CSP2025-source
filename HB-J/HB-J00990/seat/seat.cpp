#include<bits/stdc++.h>
using namespace std;
struct S{
    int i,k;
};
bool cmp(S a,S b)
{
    return a.k>b.k;
}
S a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i].k;
        a[i].i=i;
    }
    sort(a+1,a+n*m+1,cmp);
    int i=1;
    while(a[i].i!=1)
    {
        i++;
    }
    c=i/n;
    if(i%n!=0)
    {
        c++;
    }
    r=i-(c-1)*n;
    if(c%2==0)
    {
        r=n-r+1;
    }
    cout<<c<<' '<<r;
    return 0;
}
