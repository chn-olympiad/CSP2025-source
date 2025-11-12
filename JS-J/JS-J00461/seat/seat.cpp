#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
    return x>y;
}
int a[11][11],b[105];
int n,m,c,r,d;
signed main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>b[i];
    }
    int gg=b[1];
    sort(b+1,b+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(b[i]==gg)
        {
            d=i;
            break;
        }
    }
    int k=d/n;
    if(d%n!=0)  k++;
    int kk=d%n;
    if(k%2==0&&kk!=0) kk=n-kk+1;
    if(k%2==0&&kk==0)  kk=1;
    if(k%2==1&&kk==0)  kk=n;
    cout<<k<<" "<<kk;
    return 0;
}
