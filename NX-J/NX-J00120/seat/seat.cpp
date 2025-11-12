#include<bits/stdc++.h>
using namespace std;
int n,m,nm,wz,h,l;
struct Node{
    int cj,xh;
};
Node a[110];
bool cmp(Node x,Node y)
{
    return x.cj>y.cj;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=nm;i++)
    {
        cin>>a[i].cj;
        a[i].xh=i;
    }
    sort(a+1,a+nm+1,cmp);
    for(int i=1;i<=nm;i++) if(a[i].xh==1) wz=i;
    l=(wz+n-1)/n;
    if(l%2==1) h=wz-n*(l-1);
    else h=n*l-wz+1;
    cout<<l<<" "<<h;
    return 0;
}
