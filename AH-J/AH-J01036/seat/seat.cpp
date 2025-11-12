#include<bits/stdc++.h>
using namespace std;
int i,n,m,k,c,r=1,a[105];
bool cmp(int x,int y)
{
    if(x>y)return 1;
    else return 0;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++)
        cin>>a[i];
    k=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(i=1;i<=n*m;i++)
        if(a[i]==k)
        {
            k=i;
            break;
        }
    for(i=1;i<=k;i++)
    {
        if((i-1)%n==0)
            c++;
        else if(c%2)r++;
            else r--;
    }
    cout<<c<<' '<<r;
    return 0;
}
