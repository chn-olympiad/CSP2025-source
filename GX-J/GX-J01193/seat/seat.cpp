#include <bits/stdc++.h>
using namespace std;
long long a[10000000];
int n,m;
int rx,ry;
int pos;
bool cmp(int x,int y){
    return x>=y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++) {
        if (a[i]==R) pos=i;
    }

    if (pos%n==0) rx=pos/n;
    else rx=pos/n+1;
    if (rx%2==1){
        ry=pos%n;
        if (ry==0) ry=n;
    }
    else {
        if (pos%n==0) ry=1;
        else ry=n-pos%n+1;
    }
    cout<<rx<<" "<<ry;
    return 0;
}
