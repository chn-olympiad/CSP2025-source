#include<bits/stdc++.h>
using namespace std;
int n,m,l,a[1005];
bool vmp(int x,int y)
{
    return x>=y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    l=a[1];
    for(int i=2;i<=n*m;i++) cin>>a[i];
    sort(a+1,a+n*m+1,vmp);
//    for(int i=1;i<=n*m;i++) cout<<a[i]<<endl;
//    cout<<l;
    for(int i=1,j=1,k=1,bj=1;;j+=bj,k++)
    {
//        cout<<i<<","<<j<<"  "<<a[k]<<endl;
        if(j==n+1) bj=-1,j=n,i++;
        if(j==0) bj=1,j=1,i++;
        if(a[k]==l)
        {
            cout<<i<<" "<<j;
            return 0;
        }

    }
    return 0;
}
