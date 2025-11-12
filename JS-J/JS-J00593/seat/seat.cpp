#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
struct st{
    int s,id;
    bool operator <(const st &rhs)const{
        return s>rhs.s;
    }
}a[105];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int i;
    for(i=0;i<n*m;i++)
    {
        cin >> a[i].s;
        a[i].id=i;
    }
    sort(a,a+n*m);
    for(i=0;a[i].id!=0;i++);
    cout<<int(i/n)+1<<" ";
    if(int(i/n)%2==0)
    {
        cout<<i%n+1;
    }
    else
    {
        cout<<n-i%n;
    }
    return 0;
}
