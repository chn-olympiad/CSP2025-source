#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int a[114514];
/*bool cmp(int x,int y)
{
    if(x>y) return x>y;
    else return x<y;
}*/
void pd(int x)
{
    int i=1;
    while(x>=n)
    {

        x-=n;
        i++;
    }
    if(i%2==0) cout<<i<<' '<<n-x+1<<endl;
    else cout<<i<<' '<<x<<endl;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
        if(i==0) r=a[i];
    }
    sort(a,a+m*n);
    for(int i=0;i<n*m;i++)
        if(a[i]==r) pd(n*m-i);
    return 0;
}
