#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N],r,x,y;
bool cmp(int i,int j)
{
    return i>j;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
        if(i==1)
            r=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    cout<<endl;
    for(int i=1;i<=n*m;i++)
        if(a[i]==r)
            r=i;
    x=(r-1)/n+1;
    y=r%n;
    if(n%2==0)
        y=n-y+1;
    printf("%d %d",x,y);
    return 0;
}
